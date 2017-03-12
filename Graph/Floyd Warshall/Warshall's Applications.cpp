using vi = vector <int>;
using vvi = vector < vi >;

void transtitive_closure( vvi &mat )
{
    int V = mat.size();

    for( int via = 0; via < V; via++ )
    {
        for( int from = 0; from < V; from++ )
        {
            for( int to = 0; to < V; to++ )
            {
                mat[ from ][ to ] |= ( mat[ from ][ via ] & mat[ via ][ to ] );
            }
        }
    }
}

///finding a path between two nodes that maximizes the minimum cost
void mini_max( vvi &mat )
{
    int V = mat.size();

    for( int via = 0; via < V; via++ )
    {
        for( int from = 0; from < V; from++ )
        {
            for( int to = 0; to < V; to++ )
            {
                mat[ from ][ to ] = min( mat[ from ][ to ], max( mat[ from ][ via ], mat[ via ][ to ] ) );
            }
        }
    }
}

///finding a path between two nodes that minimizes the maximum cost.
///Eg: max load a truck can carry from one node to another node where
///the paths have weight limit
void maxi_min( vvi &mat )
{
    int V = mat.size();

    for( int via = 0; via < V; via++ )
    {
        for( int from = 0; from < V; from++ )
        {
            for( int to = 0; to < V; to++ )
            {
                mat[ from ][ to ] = max( mat[ from ][ to ], min( mat[ from ][ via ], mat[ via ][ to ] ) );
            }
        }
    }
}
