## Morris Inorder 


<p align="center">
  <img src="https://user-images.githubusercontent.com/86841935/193724055-d3437449-1f76-4fc7-b2a3-d503ec6deb6b.jpg" width="350" title="hover text">

</p>

```
current= root;
while(root != NULL)
{
    if( left==NULL ) 
    {
        print current
        current= current->right
    }
    
    else
    {
        pred=find(Curr)
        if(pred->right == NULL)
        {
            pred->right = current;
            curr=curr->left;
        }

        else
        {
            pred->right = NULL;
            curr=curr->right;
        }
    }
}
```

