/*#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	ScavTrap	yoyo("Yoyo");

	yoyo.attack("John");
	john.takeDamage(yoyo.getattack());
	peter.attack("John");
	john.takeDamage(1);
	john.beRepaired(2);
	john.attack("Peter");
	peter.takeDamage(11);
	peter.beRepaired(5);
	return (0);
}
*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
    printSection("1. CHAINAGE DES CONSTRUCTEURS ET DESTRUCTEURS");
    {
        std::cout << "-> Tentative de creation d'un ScavTrap :" << std::endl;
        std::cout << "*(On doit voir : 1. ClapTrap costruct, 2. ScavTrap construct)*\n" << std::endl;
        
        ScavTrap scav("SC4V-TP");

        std::cout << "\n-> Fin du scope de test :" << std::endl;
        std::cout << "*(On doit voir : 1. ScavTrap destruct, 2. ClapTrap destruct)*\n" << std::endl;
    }

    // =========================================================================
    // 2. TEST DES STATISTIQUES ET DE L'ATTAQUE SPÉCIFIQUE
    // =========================================================================
    printSection("2. STATISTIQUES & ATTAQUE SPECIFIQUE DE SCAVTRAP");
    {
        std::cout << "-> Initialisation de Sereno, le ScavTrap :" << std::endl;
        ScavTrap sereno("Sereno");

        std::cout << "\n-> Test de l'attaque specifique (Doit afficher 20 degats et un message propre) :" << std::endl;
        sereno.attack("un vilain Psychopathe");

        std::cout << "\n-> Test des points de vie (100 PV de base pour un ScavTrap) :" << std::endl;
        sereno.takeDamage(40); // Reste 60 PV
        sereno.beRepaired(20);  // Remonte a 80 PV

        std::cout << "\n-> Test de la capacite speciale specifique a ScavTrap :" << std::endl;
        sereno.guardGate();

	std::cout <<"\n-> Local memory is deleted" << std::endl;
    }

    // =========================================================================
    // 3. ENERGIE & ETATS CRITIQUES (50 PE DE BASE)
    // =========================================================================
    printSection("3. ETATS CRITIQUES DE SCAVTRAP (PV ET PE)");
    {
        ScavTrap exhausted("Bordeline-TP");

        std::cout << "\n-> Subir des degats fatals (Plus de 100 PV) :" << std::endl;
        exhausted.takeDamage(150); // KO technique !

        std::cout << "\n-> Tenter d'utiliser GuardGate ou d'attaquer une fois KO :" << std::endl;
        exhausted.attack("cible");
        exhausted.guardGate(); // Selon ton choix de design, GuardGate peut echouer si le robot est mort
        exhausted.beRepaired(10);
	std::cout <<"\n-> Local memory is deleted" << std::endl;
    }

    // =========================================================================
    // 4. LE POLYMORPHISME (TEST BONUS TRÈS APPRÉCIÉ EN SOUTENANCE)
    // =========================================================================
    printSection("4. TEST DU POLYMORPHISME (POINTEUR CLAPTRAP)");
    {
        std::cout << "-> Creation d'un ScavTrap stocke dans un pointeur ClapTrap :" << std::endl;
        ClapTrap* poly = new ScavTrap("PolyMorph");

        std::cout << "\n-> Appel de l'attaque :" << std::endl;
        std::cout << "*(Si ton attack() est virtuelle dans ClapTrap, c'est le message de ScavTrap qui s'affiche !)*" << std::endl;
        poly->attack("une cible test");

        std::cout << "\n-> Destruction via le pointeur :" << std::endl;
        std::cout << "*(Si ton destructeur est virtuel dans ClapTrap, les DEUX destructeurs s'appellent !)*" << std::endl;
        delete poly;
    }

    // =========================================================================
    // 5. VALIDATION DE LA FORME CANONIQUE
    // =========================================================================
    printSection("5. VALIDATION FORME CANONIQUE (SCAVTRAP)");
    {
        std::cout << "-> Original :" << std::endl;
        ScavTrap original("Original");

        std::cout << "\n-> Recopie :" << std::endl;
        ScavTrap copie(original);

        std::cout << "\n-> Assignation :" << std::endl;
        ScavTrap assigne("Temporaire");
        assigne = original;
        
        std::cout << "\n-> Nettoyage :" << std::endl;
    }

    printSection("FIN DES TESTS");
    return 0;
}
