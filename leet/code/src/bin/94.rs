use core::cell::RefCell;
use std::{borrow::Borrow, rc::Rc};

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

// recursive implementation with appending vectors
pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut v: Vec<i32> = Vec::new();

    if let Some(r) = root {
        // current node has a left child
        if r.borrow_mut().left.is_some() {
            v.append(&mut self::inorder_traversal(r.borrow_mut().left.clone()));
        }

        // add root node
        v.push(r.borrow_mut().val);

        // current node has a right child
        if r.borrow_mut().right.is_some() {
            v.append(&mut self::inorder_traversal(r.borrow_mut().right.clone()))
        }
    }

    v
}

// TODO recursive implementation with helper

// Iterative implementation with a stack
pub fn inorder_traversal_stack(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut v: Vec<i32> = Vec::new();
    let mut stack: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
    let mut node = root;

    while !stack.is_empty() || node.is_some() {
        while let Some(n) = node {
            node = n.borrow_mut().left.take();
            stack.push(Some(n));
        }
        if let Some(Some(n)) = stack.pop() {
            v.push(n.borrow_mut().val);
            node = n.borrow_mut().right.take();
        }
    }
    v
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn inorder_traversal_example_1() {
        let mut root = TreeNode::new(1);
        let mut two = TreeNode::new(2);
        two.left = Some(Rc::new(RefCell::new(TreeNode::new(3))));
        root.right = Some(Rc::new(RefCell::new(two)));

        assert_eq!(
            inorder_traversal(Some(Rc::new(RefCell::new(root)))),
            vec![1, 3, 2]
        );
        assert_eq!(
            inorder_traversal_stack(Some(Rc::new(RefCell::new(root)))),
            vec![1, 3, 2]
        );
    }

    #[test]
    fn inorder_traversal_example_2() {
        assert_eq!(inorder_traversal(None), vec![]);
    }

    #[test]
    fn inorder_traversal_example_3() {
        assert_eq!(
            inorder_traversal(Some(Rc::new(RefCell::new(TreeNode::new(1))))),
            vec![1]
        )
    }
}
