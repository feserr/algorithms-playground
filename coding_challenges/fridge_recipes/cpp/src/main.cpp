/*
 * Copyright 2022 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/algorithms-playground#license
 */

#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Ingredient {
  string name;
  uint32_t amount;
};

struct Recipe {
  string name;
  unordered_set<Ingredient> ingredients;
};

class Fridge {
  void Startup() {
    // inits the private members.
  }

  vector<Recipe> GetPossibleRecipes() {
    vector<Recipe> possible_recipes;
    unordered_map<Recipe, int> partial_recipe;

    for (const auto& ingredient : ingredients_) {
      auto recipes_iterator = recipes_from_ingredient_.find(ingredient);
      if (recipes_iterator == recipes_from_ingredient_.end()) continue;
      auto recipes = recipes_iterator;

      for (const auto& recipe : recipes_) {
        auto it_part_rec = partial_recipe.find(recipe);
        if (it_part_rec == partial_recipe.end()) {
          partial_recipe[recipe] = recipe.amount - 1;
        } else {
          --partial_recipe[recipe];
        }

        if (partial_recipe[recipe] == 0) {
          possible_recipes.emplace_back(&recipe);
        }
      }
    }

    return possible_recipes;
  }

 private:
  vector<Ingredient> ingredients_;
  list<Recipe> recipes_;
  unordered_map<Ingredient, list<Recipe*>> recipes_from_ingredient_;
};

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  return 0;
}