#include <iostream>
#include <string>

#ifndef __DOUBLE_BRACKET_HPP
#define __DOUBLE_BRACKET_HPP

size_t PFC(size_t p1, size_t p2) {
  // std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (true) {
    std::string entreeP1;
    std::string entreeP2;
    if (!std::cin) {
      exit(1);
    }

    // std::cout << "P1 joue PFC : " << std::endl;
    getline(std::cin, entreeP1); // P1 JOUE EN PREMIER
    // std::cout << entreeP1 << std::endl;

    // std::cout << "P2 joue PFC : " << std::endl;
    getline(std::cin, entreeP2); // P2 JOUE SECOND
    // std::cout << entreeP2 << std::endl;
    // std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (entreeP1 == entreeP2) {
      std::cout << "Egalité" << std::endl;

    } else if ((entreeP1 == "pierre" && entreeP2 == "ciseaux") ||
               (entreeP1 == "feuille" && entreeP2 == "pierre") ||
               (entreeP1 == "ciseaux" && entreeP2 == "feuille")) {
      return p1;
    } else if ((entreeP1 != "pierre" && entreeP1 != "feuille" &&
                entreeP1 != "ciseaux") ||
               (entreeP2 != "pierre" && entreeP2 != "feuille" &&
                entreeP2 != "ciseaux")) {
      std::cout << "ERREUR D'ENTRÉE PFC" << std::endl;
    } else {
      return p2;
    }
  }
}

size_t POF(size_t p1, size_t p2) {
  // std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //  FACE GAGNERA TOUJOURS
  //  P1 JOUERA TOUJOURS EN PREMIER, DONC IL EST RESPONSABLE DE LA VICTOIRE
  std::string entreeP1;
  // std::cout << "P1 doit choisir Pile ou Face : " << std::endl;
  getline(std::cin, entreeP1);
  // std::cout << entreeP1 << std::endl;
  // std::cin.ignore (1);
  if (entreeP1 == "face") {
    //    std::cin.ignore (1);
    return p1;
  } else {
    return p2;
  }
}

size_t getTheNumber(size_t p1, size_t p2) {
  // std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
  size_t number{3};
  size_t entreep1;
  size_t entreep2;
  while (true) {
    std::string tmp;
    // std::cout << "P1 choisit son nombre" << std::endl;
    getline(std::cin, tmp);
    entreep1 = atoll(tmp.c_str());
    // std::cout << entreep1 << std::endl;
    // std::cout << "P2 choisit son nombre" << std::endl;
    getline(std::cin, tmp);
    entreep2 = atoll(tmp.c_str());
    // std::cout << entreep2 << std::endl;
    if (entreep1 == entreep2)
      continue;
    // DANS UN VRAI JEU FONCTIONNEL, LE NUMBER CHANGE DE FAÇON ALÉATOIRE
    if (entreep1 == number)
      return p1;
    else
      return p2;
  }
}

size_t match(size_t P1, size_t P2) {
  size_t scoreP1{0};
  size_t scoreP2{0};
  size_t gamePFC;
  size_t gamePOF;
  size_t gameGTN;
  bool runGamePFC{true};
  bool runGamePOF{true};
  bool runGameGTN{true};

  while (true) {
    if ((scoreP1 == 2) && (scoreP2 == 0 || scoreP2 == 1)) {
      return P1;
    } else if ((scoreP2 == 2) && (scoreP1 == 0 || scoreP1 == 1)) {
      return P2;
    }
    if (runGamePFC) {
      gamePFC = PFC(P1, P2);
      if (P1 == gamePFC) {
        ++scoreP1;
        runGamePFC = false;
        continue;
      } else {
        ++scoreP2;
        runGamePFC = false;
        continue;
      }
    }
    if (runGamePOF) {
      gamePOF = POF(P1, P2);
      if (P1 == gamePOF) {
        ++scoreP1;
        runGamePOF = false;
        continue;
      } else {
        ++scoreP2;
        runGamePOF = false;
        continue;
      }
    }
    if (runGameGTN) {
      gameGTN = getTheNumber(P1, P2);
      if (P1 == gameGTN) {
        ++scoreP1;
        runGameGTN = false;
        continue;
      } else {
        ++scoreP2;
        runGameGTN = false;
        continue;
      }
    }
  }
}

#endif
