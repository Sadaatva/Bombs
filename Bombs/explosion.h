#pragma once

#include <vector>

class Explosion{
public:
    int detonate(std::vector<std::vector<int>>& bombs, std::vector<bool>& detonated, int i);
    std::pair<int, std::vector<int>> maximumDetonated(std::vector<std::vector<int>>& bombs);
};

