void printPath(int u)
{
    if ( u == start )
    {
        printf("%d", u);
        return;
    }
    printPath( path[u] );   // recursive call: to make the output format: s -> ... -> t
    printf(" %d", u);
}
