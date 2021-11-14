

int binary_find (int *array,int len,int target)      
    int l=0,r=len-1;
    int mid = (l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(array[mid]==target)return mid;
        if(array[mid]>target) r=mid-1;
        else l=mid+1;
    }
    return array[mid]==target?mid:-1;
}


int binary_find_fir (int *array,int len,int target)     
{
    int l=0,r=len-1;
    int mid = (l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(array[mid]>=target) r=mid-1;
        else l=mid+1;
    }
    return array[l]==target?mid:-1;
}


int binary_find_last (int *array,int len,int target)        
{
    int l=0,r=len-1;
    int mid = (l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(array[mid]>target) r=mid-1;
        else l=mid+1;
    }
    return array[r]==target?mid:-1;
}
