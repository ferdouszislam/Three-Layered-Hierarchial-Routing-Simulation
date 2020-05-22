/**

    CSE338.2 Final Assignment Question-4(Section-B)

    Simulation to find x,y,z(clusters, regions, routers) combinations
    that meet the condition: x*y*z == TOTAL_ROUTERS(4800) and create the smallest routing table possible
    the range for x,y,z is [12,18], general vicinity of 16

    Name: Ferdous Zeaul Islam
    NSU ID: 1731136042
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// total routers available
const int TOTAL_ROUTERS = 4800;

// general vicinity for 16 = 12-20 (assumed)
const int VICINITY_START = 12, VICINITY_END = 20;


// vectors to hold valid trios of cluster, region and router
vector<int> validClusterNumbers,validRegionNumbers,validRouterNumbers;



// function to find optimal number of clusters, regions per cluster, routers per region
void findOptimalDistribution()
{

    // loop through for number of routers that are inside the general vicinity of 16
    for(int trialNumberOfRouters=VICINITY_START;trialNumberOfRouters<=VICINITY_END;trialNumberOfRouters++){


        if(TOTAL_ROUTERS%trialNumberOfRouters == 0)
        {
            // this is a potential router number
            // now find the corresponding region and cluster numbers

            int otherDivisor = TOTAL_ROUTERS/trialNumberOfRouters;

            // divisor pairs of the 'otherDivisor' variable
            // are potential region and router number for this cluster number

            // find divisor pair for 'otherDivisor' inside the vicinity
            for(int trialNumberOfRegions = VICINITY_START; trialNumberOfRegions<=VICINITY_END; trialNumberOfRegions++){

                if(otherDivisor%trialNumberOfRegions==0){
                    // divisor pair found

                    // first value of the divisor pair is a potential region number

                    // second value of the divisor pair is a potential number of clusters
                    int trialNumberOfClusters = otherDivisor/trialNumberOfRegions;

                    if( trialNumberOfClusters >= VICINITY_START && trialNumberOfClusters <=VICINITY_END )
                    {
                        // all three trial values for router, region and clusters are valid
                        // store the combination in three vectors at same position

                        validClusterNumbers.push_back(trialNumberOfClusters);
                        validRegionNumbers.push_back(trialNumberOfRegions);
                        validRouterNumbers.push_back(trialNumberOfRouters);

                    }

                }

            }

        }

    }

}


int main()
{
    findOptimalDistribution();

    int minimumRoutingTableSize = TOTAL_ROUTERS, minimumRoutingTableSizePosition;

    for(int i=0;i<validClusterNumbers.size();i++){

        cout<<"Clusters = "<<validClusterNumbers[i]<<" Regions per cluster = "<<validRegionNumbers[i]<<" Routers per region = "<<validRouterNumbers[i];
        cout<<endl;

        // routing table size = number of clusters excluding it's own cluster
        //                      + number of regions excluding it's own region
        //                      + total routers in it's region
        int routingTableSize = (validClusterNumbers[i]-1) + (validRegionNumbers[i]-1) + validRouterNumbers[i];
        cout<<"Size of Routing Table = "<<routingTableSize;

        if(routingTableSize<minimumRoutingTableSize){
            minimumRoutingTableSize = routingTableSize;
            minimumRoutingTableSizePosition = i;
        }

        cout<<endl<<endl;

    }

    cout<<"Minimum routing table size possible = "<<minimumRoutingTableSize
        <<"\nAchieved with any combination of "
        <<validClusterNumbers[minimumRoutingTableSizePosition]
        <<", "<<validRegionNumbers[minimumRoutingTableSizePosition]
        <<", "<<validRouterNumbers[minimumRoutingTableSizePosition]<<" clusters, regions, routers"
        <<endl<<endl;

    return 0;
}
