/*#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	
	peter.attack("John");
	john.takeDamage(1);
	john.beRepaired(2);
	john.attack("Peter");
	peter.takeDamage(11);
	peter.beRepaired(5);
	return (0);
}*/

#include "ClapTrap.hpp"

void printSection(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    // =========================================================================
    // 1. COMPORTEMENT DE BASE AVEC 0 DEGAT (CE QUE VEUT LE SUJET)
    // =========================================================================
    printSection("1. COMPORTEMENT DE BASE (0 DEGAT)");
    {
        std::cout << "-> Initialisation de CL4P-TP (Statistiques par defaut) :" << std::endl;
        ClapTrap claptrap("CL4P-TP");

        std::cout << "\n-> Attaque initiale (Doit afficher 0 points de degat) :" << std::endl;
        claptrap.attack("un Skag inoffensif");
        
        std::cout << "\n-> Reparation standard (Doit consommer 1 Energie) :" << std::endl;
        claptrap.beRepaired(5);

	std::cout << "\n-> Le ClapTrap meurt en sortie de boucle" << std::endl;
    } 

    // =========================================================================
    // 2. SIMULATION D'EVOLUTION DES DEGATS (POUR VERIFIER TA LOGIQUE)
    // =========================================================================
    printSection("2. SIMULATION DE DEGATS EVOLUTIFS");
    {
        std::cout << "-> Un nouveau ClapTrap entre dans l'arene :" << std::endl;
        ClapTrap badass("Badass-TP");

        std::cout << "\n-> /!\\ On simule l'obtention d'une arme en modifiant ses degats." << std::endl;
        std::cout << "(Note: Si ton attribut '_attackDamage' est prive, tu peux tester cela" << std::endl;
        std::cout << "via le constructeur de recopie ou en ajoutant temporairement un setter, " << std::endl;
        std::cout << "ou simplement imaginer que cette etape valide que ton 'attack()' utilise bien la variable)" << std::endl;
        
        // Si tu as fait un setter pour tes tests :
        // badass.setAttackDamage(5); 
        
        badass.attack("un Sadique");
        badass.takeDamage(4);
        badass.beRepaired(2);
	
	std::cout << "\n-> Le ClapTrap meurt en sortie de boucle" << std::endl;
    }

    // =========================================================================
    // 3. SEUIL CRITIQUE : 0 PV (LA MORT)
    // =========================================================================
    printSection("3. TEST DE KO (0 POINTS DE VIE)");
    {
        ClapTrap target("Target-TP");

        std::cout << "\n-> Target-TP subit des degats fatals :" << std::endl;
        target.takeDamage(10); // Il avait 10 PV par defaut, il tombe a 0.

        std::cout << "\n-> Tentatives d'actions sur un robot KO (Rien ne doit se passer) :" << std::endl;
        target.attack("un enemi");
        target.beRepaired(5);
        
        std::cout << "\n-> Subir des degats supplementaires alors qu'il est deja a 0 PV :" << std::endl;
        target.takeDamage(5); // Doit rester bloque a 0 PV, pas de PV negatifs bizarres.
	
	std::cout << "\n-> Le ClapTrap meurt en sortie de boucle" << std::endl;
    }

    // =========================================================================
    // 4. SEUIL CRITIQUE : 0 PE (L'EPUISEMENT)
    // =========================================================================
    printSection("4. TEST D'EPUISEMENT (0 ENERGIE)");
    {
        ClapTrap exhausted("NoEnergy-TP");

        std::cout << "\n-> Le robot vide ses 10 Points d'Energie :" << std::endl;
        for (int i = 0; i < 10; i++) {
            exhausted.attack("un moustique");
        }

        std::cout << "\n-> 11eme action tentee (Doit echouer par manque d'energie) :" << std::endl;
        exhausted.beRepaired(10);
        exhausted.attack("un enemi");

        std::cout << "\n-> Recevoir des degats (Ne coute pas d'energie, doit s'afficher) :" << std::endl;
        exhausted.takeDamage(3);
	
	std::cout << "\n-> Le ClapTrap meurt en sortie de boucle" << std::endl;
    }

    // =========================================================================
    // 5. TEST DE LA FORME CANONIQUE ORTHODOXE
    // =========================================================================
    printSection("5. VALIDATION FORME CANONIQUE");
    {
        std::cout << "-> Creation de l'original :" << std::endl;
        ClapTrap original("Original-TP");

        std::cout << "\n-> Test du constructeur de recopie :" << std::endl;
        ClapTrap copie(original);

        std::cout << "\n-> Test de l'operateur d'assignation (=) :" << std::endl;
        ClapTrap assigne("Temporaire-TP");
        assigne = original;
        
        std::cout << "\n-> Destruction en chaine des instances de la forme canonique :" << std::endl;
    }

    printSection("FIN DES TESTS - TOUT EST OK");
    return 0;
}
