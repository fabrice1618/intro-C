/* Programme de calcul de nombres rationnels
Attention: Ne pas modifier la première partie du fichier avant la ligne 145
*/

#include <stdio.h>
#include <stdbool.h>

#define MSG_SUCCESS "réussi :)"
#define MSG_FAIL    "échoué :("

typedef struct rationnel_t
{
    int num;        // Numérateur
    int den;        // Dénominateur
} Rationnel;

//bool tester_resultat(Rationnel test, Rationnel attendu);
bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();
bool test7();
bool test8();
// Les prototypes des fonctions que vous écrirez sont imposés
Rationnel addition_rationnelle(Rationnel r1, Rationnel r2);
Rationnel soustraction_rationnelle(Rationnel r1, Rationnel r2);
Rationnel multiplication_rationnelle(Rationnel r1, Rationnel r2);
Rationnel division_rationnelle(Rationnel r1, Rationnel r2);

int main()
{
    bool petit_scarabee = test1() && test2() && test3() && test4();
    bool ninja = petit_scarabee && test5() && test6() && test7() && test8();

    printf("### Niveau petit scarabée %s\n", petit_scarabee ? MSG_SUCCESS : MSG_FAIL);
    printf("### Niveau ninja %s\n", ninja ? MSG_SUCCESS : MSG_FAIL);

    return 0;
}

// Tester si le résultat obtenu est égal au résultat attendu
bool tester_resultat(Rationnel test, Rationnel attendu)
{
    bool statut_test = (test.num == attendu.num && test.den == attendu.den);

    printf("Résultat attendu: (%d/%d), valeur testée (%d/%d)\n", attendu.num, attendu.den, test.num, test.den);
    printf("Test %s\n\n", statut_test ? MSG_SUCCESS : MSG_FAIL);

    return statut_test;
}

// Test 1
bool test1()
{
    Rationnel r1 = {1, 3};
    Rationnel r2 = {4, 3};
    Rationnel attendu = {5, 3};

    printf("Test 1: addition de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( addition_rationnelle(r1, r2), attendu );
}

// Test 2
bool test2()
{
    Rationnel r1 = {4, 3};
    Rationnel r2 = {2, 3};
    Rationnel attendu = {2, 3};

    printf("Test 2: soustraction de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( soustraction_rationnelle(r1, r2), attendu );
}

// Test 3
bool test3()
{
    Rationnel r1 = {1, 2};
    Rationnel r2 = {1, 3};
    Rationnel attendu = {1, 6};

    printf("Test 3: multiplication de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( multiplication_rationnelle(r1, r2), attendu );
}

// Test 4
bool test4()
{
    Rationnel r1 = {1, 2};
    Rationnel r2 = {1, 3};
    Rationnel attendu = {3, 2};

    printf("Test 4: division de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( division_rationnelle(r1, r2), attendu );
}

// Test 5
bool test5()
{
    Rationnel r1 = {2, 3};
    Rationnel r2 = {6, 2};
    Rationnel attendu = {11, 3};

    printf("Test 5: addition de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( addition_rationnelle(r1, r2), attendu );
}

// Test 6
bool test6()
{
    Rationnel r1 = {11, 7};
    Rationnel r2 = {3, 6};
    Rationnel attendu = {15, 14};

    printf("Test 6: soustraction de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( soustraction_rationnelle(r1, r2), attendu );
}

// Test 7
bool test7()
{
    Rationnel r1 = {21, 10};
    Rationnel r2 = {15, 28};
    Rationnel attendu = {9, 8};

    printf("Test 7: multiplication de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( multiplication_rationnelle(r1, r2), attendu );
}

// Test 8
bool test8()
{
    Rationnel r1 = {5, 7};
    Rationnel r2 = {10, 3};
    Rationnel attendu = {3, 14};

    printf("Test 8: division de (%d/%d) et (%d/%d)\n", r1.num, r1.den, r2.num, r2.den);
    return tester_resultat( division_rationnelle(r1, r2), attendu );
}

// ###########################################################
// Ci-dessous les fonctions que vous devez écrire.
// Ne modifiez pas le code source au-dessus de cette ligne.
// ###########################################################
