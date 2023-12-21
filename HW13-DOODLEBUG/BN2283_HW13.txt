// ConsoleApplication23.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
/*The goal for this Project is to create a simple two-dimensional predator-prey
simulation.In this simulation the prey are ants and the predators are doodlebugs.
These critters live in a world composed of a 20 × 20 grid of cells.Only one critter
may occupy a cell at a time.The grid is enclosed, so a critter is not allowed to move
off the edges of the world.Time is simulated in time steps.Each critter performs
some action every time step*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int GRID_SIZE = 20;
const int NUM_DOODLEBUGS = 5;
const int NUM_ANTS = 100;

class Organism {
public:
    virtual bool isAnt() const {
        return false;  // By default, the organism is not an ant
    }

    virtual void move(Organism* grid[GRID_SIZE][GRID_SIZE], int x, int y) = 0;
    virtual void breed(Organism* grid[GRID_SIZE][GRID_SIZE], int x, int y) = 0;
    virtual ~Organism() {}
};

class Ant : public Organism {
public:
    void move(Organism* grid[GRID_SIZE][GRID_SIZE], int x, int y) override {
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int randomDirection = rand() % 4;  // Randomly select a direction (0: up, 1: down, 2: left, 3: right)

        int newX = x + directions[randomDirection][0];
        int newY = y + directions[randomDirection][1];

        // Check if the new position is within the grid and unoccupied
        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == nullptr) {
            // Move the ant to the new position
            grid[newX][newY] = grid[x][y];
            grid[x][y] = nullptr;
        }
    }

    void breed(Organism* grid[GRID_SIZE][GRID_SIZE], int x, int y) override {
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            // Ensure the new position is within the grid and unoccupied
            if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == nullptr) {
                // Create a new ant in the adjacent cell
                grid[newX][newY] = new Ant();
                break;  // Breeding is successful, exit the loop
            }
        }
    }
    bool isAnt() const override {
        return true;  // This organism is an ant
    }
};

class Doodlebug : public Organism {
private:
    int timeSinceLastMeal;

    
public:
    // Method to check if the doodlebug has starved
    bool hasStarved() const {
        return timeSinceLastMeal >= 3;
    }
    Doodlebug() : timeSinceLastMeal(0) {}
    

    void move(Organism* grid[GRID_SIZE][GRID_SIZE], int x, int y) override {
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int randomDirection = rand() % 4;  // Randomly select a direction (0: up, 1: down, 2: left, 3: right)

        // Attempt to move in the random direction
        int newX = x + directions[randomDirection][0];
        int newY = y + directions[randomDirection][1];

        // Check if the new position is within the grid
        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
            // If the new position contains an ant, the doodlebug eats the ant
            if (grid[newX][newY] != nullptr && grid[newX][newY]->isAnt()) {
                delete grid[newX][newY];  // Delete the eaten ant
                grid[newX][newY] = grid[x][y];  // Move the doodlebug to the ant's position
                grid[x][y] = nullptr;  // The previous position is now empty
                timeSinceLastMeal = 0;  // Reset timeSinceLastMeal after eating
            }
            // Check for starvation
            if (hasStarved(true)) {
                // Delete the starving doodlebug from its current position
                delete grid[x][y];
                grid[x][y] = nullptr;
            }
        }
    }
    void breed(Organism* grid[GRID_SIZE][GRID_SIZE], int x, int y) override
    {
        iint directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        for (int i = 0; i < 4; ++i) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            // Ensure the new position is within the grid and there is at least one neighboring ant
            if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE &&
                grid[newX][newY] != nullptr && grid[newX][newY]->isAnt()) {
                // Create a new doodlebug in the adjacent cell
                if (grid[x][y] == nullptr) {
                    grid[x][y] = new Doodlebug();
                    break;  // Breeding is successful, exit the loop
                }
            }
        }
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    Organism* grid[GRID_SIZE][GRID_SIZE] = { nullptr }; // Initialize grid with nullptr (empty cells)

    // Place ants on the grid
    for (int i = 0; i < NUM_ANTS; ++i) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != nullptr); // Keep finding random positions until an empty cell is found
        grid[x][y] = new Ant(); // Place the ant in the grid
    }

    // Place doodlebugs on the grid
    for (int i = 0; i < NUM_DOODLEBUGS; ++i) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != nullptr); // Keep finding random positions until an empty cell is found
        grid[x][y] = new Doodlebug(); // Place the doodlebug in the grid
    }

    // Main simulation loop (for 100 time steps)
    for (int timeStep = 0; timeStep < 100; ++timeStep) {
        // Move doodlebugs
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (grid[i][j] != nullptr && !grid[i][j]->isAnt()) {
                    grid[i][j]->move(grid, i, j);
                }
            }
        }
        

        // Move ants
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (grid[i][j] != nullptr && grid[i][j]->isAnt()) {
                    grid[i][j]->move(grid, i, j);
                }
            }
        }

        // Breed ants and place offspring directly in the grid
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (grid[i][j] != nullptr && grid[i][j]->isAnt() && timeStep % 3 == 0) {
                    grid[i][j]->breed(grid, i, j);
                }
            }
        }

        // Breed doodlebugs and place offspring directly in the grid
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                if (grid[i][j] != nullptr && !grid[i][j]->isAnt() && timeStep % 8 == 0) {
                    grid[i][j]->breed(grid, i, j);
                }
            }
        }
        

        // Print grid state
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (grid[i][j] != nullptr) {
                    if (grid[i][j]->isAnt()) {
                        cout << "O ";  // O represents an Ant
                    }
                    else {
                        cout << "X ";  // X represents a Doodlebug
                    }
                }
                else {
                    cout << "- ";     // - represents an empty cell
                }
            }
              cout << endl;
        }
              cout << endl; // Move to the next row in the grid
        

        
         cout << "Press Enter to move to the next time step...";
         cin.ignore(); // Wait for user input
    }

    // Clean up memory after the simulation is done
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                delete grid[i][j];  // Delete each organism object
                grid[i][j] = nullptr;  // Set the grid cell to nullptr after deletion
            }
        }


    return 0;
}

