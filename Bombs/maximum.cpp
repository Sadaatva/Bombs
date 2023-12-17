#include <iostream>
#include <vector>
#include <cmath>
#include "explosion.h"

std::pair<int, std::vector<int>> Explosion::maximumDetonated(std::vector<std::vector<int>>& bombs){
	int maxDetonatedBombs = 0;
    std::vector<int> maxDetonatedBombCoords;
    int n = bombs.size();

    for (int i = 0; i < n; ++i){
        std::vector<bool> detonated(bombs.size(), false);
        detonated[i] = true;
        int r = 1 + detonate(bombs, detonated, i);
        if (r > maxDetonatedBombs) {
            maxDetonatedBombs = r;
            maxDetonatedBombCoords = bombs[i];
        }
    }
    return std::make_pair(maxDetonatedBombs, maxDetonatedBombCoords);
}
