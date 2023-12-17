#include <iostream>
#include <vector>
#include <cmath>
#include "explosion.h"

int Explosion::detonate(std::vector<std::vector<int>>& bombs, std::vector<bool>& detonated, int i){
    int booms = 0, n = bombs.size();
        for (int j = 0; j < n; j++) {
            if (!detonated[j]) {
                int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                int x2 = bombs[j][0], y2 = bombs[j][1];
                long dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
                if (dist <= (long)r1 * r1) {
                    detonated[j] = true;
                    booms += 1 + detonate(bombs, detonated, j);
                }
            }
        }
    return booms;
}
