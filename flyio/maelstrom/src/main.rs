use anyhow::{bail, Context, Result};
use serde::{Deserialize, Serialize};
use std::io::StdoutLock;
use std::io::Write;
use uuid7::Uuid;

#[derive(Debug, Clone, Deserialize, Serialize)]
pub(crate) struct Message {
    pub src: String,
    #[serde(rename = "dest")]
    pub dst: String,
    pub body: Body,
}

#[derive(Debug, Clone, Deserialize, Serialize)]
pub(crate) struct Body {
    /// A unique integer identifier
    #[serde(skip_serializing_if = "Option::is_none")]
    msg_id: Option<usize>,

    ///A string identifying the type of message this is
    #[serde(flatten)]
    ty: Payload,

    /// For req/response, the msg_id of the request
    #[serde(skip_serializing_if = "Option::is_none")]
    in_reply_to: Option<usize>,
}

#[derive(Debug, Clone, Deserialize, Serialize)]
#[serde(tag = "type")] // internally tagged
#[serde(rename_all = "snake_case")] // rename enums keys. E.g. EchoOk -> echo_ok
pub(crate) enum Payload {
    Echo {
        echo: String,
    },
    EchoOk {
        echo: String,
    },

    Init {
        /// Indicates the ID of the node which is receiving this message
        node_id: String,
        /// Lists all nodes in the cluster, including the recipient
        node_ids: Vec<String>,
    },
    Generate {},
    GenerateOk {
        id: Uuid,
    },
    InitOk {},
    Error {
        /// The code is an integer which indicates the type of error which occurred. Maelstrom defines several error types, and you can also invent your own.
        /// Codes 0-999 are reserved for Maelstrom's use; codes 1000 and above are free for your own purposes.
        code: usize,
        /// free-form string. May contain any explanatory message you like
        text: Option<String>,
    },
}

fn send(message: &mut Message, output: &mut StdoutLock) -> Result<()> {
    // swap src and dst

    serde_json::to_writer(&mut *output, message).context("serialize response")?;
    // because stdout only flushes after a newline
    output.write_all(b"\n").context("write trailing newline")?;
    output.flush()?;

    Ok(())
}

fn main() -> Result<()> {
    // read from stdin
    let stdin = std::io::stdin().lock();
    let mut stdout = std::io::stdout().lock();

    let inputs = serde_json::Deserializer::from_reader(stdin).into_iter::<Message>();

    for input in inputs {
        let in_msg = input.context("Maelstrom input from STDIN could not be deserialized")?;
        let out_msg: Option<Message> = match in_msg.body.ty {
            // these change the payload
            Payload::Echo { echo } => Some(Message {
                src: in_msg.dst,
                dst: in_msg.src,
                body: Body {
                    msg_id: None,
                    in_reply_to: in_msg.body.msg_id,
                    ty: Payload::EchoOk { echo },
                },
            }),
            Payload::EchoOk { .. } => None,
            Payload::Init { .. } => Some(Message {
                src: in_msg.dst,
                dst: in_msg.src,
                body: Body {
                    msg_id: None,
                    in_reply_to: in_msg.body.msg_id,
                    ty: Payload::InitOk {},
                },
            }),
            Payload::InitOk {} => bail!("should never receive init_ok"),
            Payload::Generate {} => Some(Message {
                src: in_msg.dst,

                dst: in_msg.src,
                body: Body {
                    msg_id: None,
                    in_reply_to: in_msg.body.msg_id,
                    ty: Payload::GenerateOk { id: uuid7::uuid7() },
                },
            }),

            Payload::GenerateOk { .. } => None,
            _ => bail!("unimplemented message type"),
        };

        if let Some(mut message) = out_msg {
            send(&mut message, &mut stdout)?;
        }
    }

    Ok(())
}
