#include <iostream>
#include <fstream>
#include <tuple>
#include "bombs.cpp"

int main(){
    std::ifstream bombsFile("bombs.txt");
    if (!bombsFile.is_open()){
        std::cerr << "Not open" << "\n";
        return 1;
    }

    int n;
    bombsFile >> n;

    std::vector<std::vector<int>> bombs(n, std::vector<int>(3));

    for (int i = 0; i < n; ++i){
        bombsFile >> bombs[i][0] >> bombs[i][1] >> bombs[i][2];
    }

    Explosion explosion;
    
    int maxDetonatedBombs;
    std::vector<int> maxDetonatedBombCoords;

    std::tie(maxDetonatedBombs, maxDetonatedBombCoords) = explosion.maximumDetonated(bombs);

    bombsFile.close();







    std::ofstream resultFile("result.txt");
    if (!resultFile.is_open()){
        std::cerr << "Not open" << "\n";
        return 1;
    }

    resultFile << "Coordinates (x, y): " << maxDetonatedBombCoords[0] << ", " << maxDetonatedBombCoords[1] << "\n";
    resultFile << "Radius: " << maxDetonatedBombCoords[2] << "\n";
    resultFile << "Count: " << maxDetonatedBombs << "\n";

    resultFile.close();

    return 0;
}
