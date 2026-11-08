/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

typedef enum quadtree_collision_error {
    QUADTREE_COLLISION_OK = 0,
    QUADTREE_COLLISION_ERR_NULL = -100,
    QUADTREE_COLLISION_ERR_CAPACITY = -101,
    QUADTREE_COLLISION_ERR_CONVERGENCE = -102
} quadtree_collision_error_t;

const char* quadtree_collision_strerror(quadtree_collision_error_t err) {
    switch (err) {
        case QUADTREE_COLLISION_OK: return "Success";
        case QUADTREE_COLLISION_ERR_NULL: return "Encountered null pointer argument";
        case QUADTREE_COLLISION_ERR_CAPACITY: return "Capacity limit exceeded";
        case QUADTREE_COLLISION_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
