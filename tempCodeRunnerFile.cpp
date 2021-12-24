int main()
{
    AVL_Tree tree;
    tree.insertFile("udemy_courses.csv");
    tree.InOrder(tree.root);
}