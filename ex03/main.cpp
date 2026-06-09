/*
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	ScavTrap	yoyo("Yoyo");
	FragTrap	flo("Flo");
	DiamondTrap	clara("Clara");

	//clara.attack("yoyo");
	clara.whoAmI();
		//flo.highFivesGuys();
	//	yoyo.attack("John");
//		john.takeDamage(yoyo.getattack());
//		peter.attack("John");
//		john.takeDamage(1);
//		john.beRepaired(2);
//		john.attack("Peter");
//		peter.takeDamage(11);
//		peter.beRepaired(5);
	return (0);
}
*/
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

void printSection(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    // =========================================================================
    // 1. TEST DU CHAÎNAGE DES CONSTRUCTEURS (L'épreuve du diamant)
    // =========================================================================
    printSection("1. CONFIGURATION DU DIAMANT (CHAINAGE MEMOIRE)");
    {
        std::cout << "-> Tentative de creation d'un DiamondTrap :" << std::endl;
        std::cout << "*(Si l'heritage virtuel est OK, ClapTrap n'est invoque qu'UNE SEULE FOIS)*" << std::endl;
        std::cout << "*(Ordre attendu : ClapTrap -> ScavTrap -> FragTrap -> DiamondTrap)*\n" << std::endl;
        
        DiamondTrap monster("D14-MD");

        std::cout << "\n-> Destruction du DiamondTrap :" << std::endl;
        std::cout << "*(Ordre inverse attendu)*\n" << std::endl;
    }

    // =========================================================================
    // 2. LA CAPACITÉ UNIQUE : WHOAMI?
    // =========================================================================
    printSection("2. CAPACITE SPECIALE : whoAmI()");
    {
        std::cout << "-> Initialisation du monstre 'Specter' :" << std::endl;
        DiamondTrap specter("Specter");

        std::cout << "\n-> Appel de whoAmI() :" << std::endl;
        std::cout << "*(Doit afficher son nom propre 'Specter' ET son nom ClapTrap 'Specter_clap_name')*" << std::endl;
        specter.whoAmI();
    }

    // =========================================================================
    // 3. VÉRIFICATION DES STATISTIQUES HYBRIDES & DE L'ATTAQUE
    // =========================================================================
    printSection("3. VERIFICATION DES STATS HYBRIDES (PV: Frag, PE: Scav, ATK: Frag)");
    {
        DiamondTrap tyler("Tyler");

        // 1. Attaque : Doit utiliser l'attaque de SCAVTRAP (Message spécifique de ScavTrap)
        // Mais avec les dégâts de FRAGTRAP (30 dégâts) !
        std::cout << "-> Test de l'attaque (Logique ScavTrap, Puissance FragTrap) :" << std::endl;
        tyler.attack("un ennemi cobaye");

        // 2. Points de vie (FragTrap = 100 PV) & Énergie (ScavTrap = 50 PE)
        std::cout << "\n-> Test de la reserve d'energie (50 PE de ScavTrap) :" << std::endl;
        std::cout << "*(On fait une serie de réparations pour voir si on peut dépasser 10 actions)*" << std::endl;
        for (int i = 0; i < 12; i++) {
            tyler.beRepaired(1); // Consomme 1 PE à chaque fois
        }
        
        // 3. Capacités héritées des deux parents : Tout doit être accessible !
        std::cout << "\n-> Appel des fonctions speciales des deux parents :" << std::endl;
        tyler.guardGate();      // Venu de ScavTrap
        tyler.highFivesGuys();  // Venu de FragTrap
    }

    // =========================================================================
    // 4. SHADOWING & COMPORTEMENT DE LA CLASSE MÈRE
    // =========================================================================
    printSection("4. SÉPARATION DES NOMS (Diamond vs ClapTrap)");
    {
        DiamondTrap alpha("Alpha");

        std::cout << "-> Appel direct de l'attaque de la classe mere ClapTrap via le monstre :" << std::endl;
        // Permet de vérifier que l'attribut du ClapTrap sous-jacent a bien reçu le suffixe _clap_name
        alpha.ClapTrap::attack("une cible distante");
    }

    // =========================================================================
    // 5. VALIDATION DE LA FORME CANONIQUE
    // =========================================================================
    printSection("5. VALIDATION FORME CANONIQUE (DIAMONDTRAP)");
    {
        std::cout << "-> Original :" << std::endl;
        DiamondTrap original("Original");

        std::cout << "\n-> Recopie :" << std::endl;
        DiamondTrap copie(original);
        copie.whoAmI();

        std::cout << "\n-> Assignation :" << std::endl;
        DiamondTrap assigne("Temporaire");
        assigne = original;
        assigne.whoAmI();
        
        std::cout << "\n-> Nettoyage final :" << std::endl;
    }

    printSection("FIN DES TESTS");
    return 0;
}
