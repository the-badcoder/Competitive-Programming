/** Algorithm:
Flag all edges of actual MST \
then remove one flaged edges and take another edge \
and create another MST. ( Continue This Prorcess ).
**/

/**
Notice that:
1) There may not be a second MST (in case the graph it's already its MST)
2) The 2nd mst may have the same cost of the 1st \
(in case you can remove an edge, \
 but use another one with the same cost that wasn't being used before).
3) MST need (NODES-1) Edges. :)
**/

int main()
{
    scanf("%d %d", &V, &E );

    Edgelist.clear();
    sum = 0;
    mst_cost = best = 0;

    for( int i = 0; i < E; i++ )
    {
        scanf("%d %d %d", &u, &v, &w);
        Edgelist.push_back( make_pair( w, ii ( u, v ) ) );
        flag[i] = false;
    }

    sort( Edgelist.begin(), Edgelist.end() );
    UF.make_set( V );

    for( int i = 0; i < E; i++ )
    {
        if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
        {
            mst_cost += Edgelist[i].first;
            flag[i] = true;
            UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
        }
    }
    //printf("%d\n", mst_cost );
    store.clear();

    for( int j = 0; j < E; j++ )
    {
        if( flag[j] == true )
        {
            int lol = 0, ans = 0;
            UF.make_set( V );

            for( int i = 0; i < E; i++ )
            {
                if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) && i != j )
                {
                    ans += Edgelist[i].first;
                    lol++;
                    UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
                }
            }

            if( lol == V - 1 )
            {
                store.push_back( ans );
            }
        }
    }

    sort( store.begin(), store.end() );
    printf("%d %d\n", mst_cost, store[0] );

    return 0;
}
