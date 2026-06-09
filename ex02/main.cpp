/*#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	ScavTrap	yoyo("Yoyo");
	FragTrap	flo("Flo");

	flo.highFivesGuys();
	yoyo.attack("John");
	john.takeDamage(yoyo.getattack());
	peter.attack("John");
	john.takeDamage(1);
	john.beRepaired(2);
	john.attack("Peter");
	peter.takeDamage(11);
	peter.beRepaired(5);
	return (0);
}*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void printSection(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    // =========================================================================
    // 1. TEST DU CHAÎNAGE DES CONSTRUCTEURS / DESTRUCTEURS
    // =========================================================================
    printSection("1. CHAINAGE DES CONSTRUCTEURS ET DESTRUCTEURS FRAGTRAP");
    {
        std::cout << "-> Tentative de creation d'un FragTrap :" << std::endl;
        std::cout << "*(On doit voir : 1. ClapTrap construct, 2. FragTrap construct)*\n" << std::endl;
        
        FragTrap frag("FR4G-TP");

        std::cout << "\n-> Fin du scope de test :" << std::endl;
        std::cout << "*(On doit voir : 1. FragTrap destruct, 2. ClapTrap destruct)*\n" << std::endl;
    }

    // =========================================================================
    // 2. STATISTIQUES DE BASE ET ATTAQUE DE FRAGTRAP
    // =========================================================================
    printSection("2. STATISTIQUES (100 PV, 100 PE, 30 ATK) & ATTAQUE");
    {
        std::cout << "-> Initialisation de Charly, le FragTrap :" << std::endl;
        FragTrap charly("Charly");

        std::cout << "\n-> Test de l'attaque (Héritée de ClapTrap, mais doit afficher 30 degats) :" << std::endl;
        charly.attack("un Goliath enrage");

        std::cout << "\n-> Test de l'endurance (100 PE de base) :" << std::endl;
        charly.takeDamage(50); // Reste 50 PV
        charly.beRepaired(30);  // Remonte a 80 PV

        std::cout << "\n-> Test de la capacite speciale unique :" << std::endl;
        charly.highFivesGuys();
    }

    // =========================================================================
    // 3. LA GRANDE CONFRONTATION (TEST DE COEXISTENCE DES 3 CLASSES)
    // =========================================================================
    printSection("3. COMPARAISON ET COEXISTENCE (CLAP VS SCAV VS FRAG)");
    {
        std::cout << "-> Creation d'une armee mixte :" << std::endl;
        ClapTrap clap("Clappy");
        ScavTrap scav("Scavvy");
        FragTrap frag("Fraggy");

        std::cout << "\n-> Comparaison des puissances d'attaque :" << std::endl;
        clap.attack("la meme cible"); // Doit afficher 0 degat
        scav.attack("la meme cible"); // Doit afficher 20 degats (Message Scav)
        frag.attack("la meme cible"); // Doit afficher 30 degats (Message Clap)

        std::cout << "\n-> Capacites speciales respectives :" << std::endl;
        scav.guardGate();
        frag.highFivesGuys();
    }

    // =========================================================================
    // 4. ETATS CRITIQUES DE FRAGTRAP
    // =========================================================================
    printSection("4. SEUILS CRITIQUES (0 PV)");
    {
        FragTrap deadFrag("Sad-TP");

        std::cout << "\n-> Sad-TP encaisse un coup fatal :" << std::endl;
        deadFrag.takeDamage(200); // Meurt instantanément

        std::cout << "\n-> Tentatives d'actions post-mortem (Rien ne doit se passer) :" << std::endl;
        deadFrag.attack("un enemi");
        deadFrag.beRepaired(20);
        deadFrag.highFivesGuys(); // Optionnel : Selon ton choix, un robot mort ne peut plus High Five !
    }

    // =========================================================================
    // 5. VALIDATION DE LA FORME CANONIQUE (FRAGTRAP)
    // =========================================================================
    printSection("5. VALIDATION FORME CANONIQUE (FRAGTRAP)");
    {
        std::cout << "-> Original :" << std::endl;
        FragTrap original("Original");

        std::cout << "\n-> Recopie :" << std::endl;
        FragTrap copie(original);

        std::cout << "\n-> Assignation :" << std::endl;
        FragTrap assigne("Temporaire");
        assigne = original;
        
        std::cout << "\n-> Nettoyage final :" << std::endl;
    }

    printSection("FIN DES TESTS");
    return 0;
}
