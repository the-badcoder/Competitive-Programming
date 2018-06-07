
const int res = 1e5 + 10;

bool mark[ res ];

void seive()
{
    memset( mark, true, sizeof mark );

    for( int i = 4; i <= res; i += 2 )
    {
        mark[ i ] = false;
    }
    int sq = sqrt( res );

    mark[ 2 ] = true;

    for( int i = 3; i <= sq; i += 2 )
    {
        if( mark[ i ] == true )
        {
            for( int j = i * i; j <= res; j += ( 2 * i ) )
            {
                mark[ j ] = false;
            }
        }
    }
}

