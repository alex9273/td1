#include <iostream>
#include <string>
#include <vector>
using namespace std;


/// <summary>
/// Demande phrase et retourne la r�ponse.
/// </summary>
/// <returns></returns>
string DemanderPhrase()
{
    cout << "Saisissez une phrase : ";
    string phrase;
    getline(cin, phrase);
    return phrase;
}

/// <summary>
/// prend une phrase et retourne un vecteur contenant chaque mot de celle-ci
/// </summary>
/// <returns></returns>
vector<string> S�parerMots(string phrase)
{
    // � travailler...
    vector<string> mots;
    int derni�reEspace = -1;
    for (int i = 0; i < phrase.size(); ++i)
    {
        if (phrase.at(i) == ' ') 
        {

            // terrible...
            string nouveaumot = "";
            for (int j = derni�reEspace + 1; j < i; ++j) 
            {
                nouveaumot += phrase.at(j);
            }
            derni�reEspace = i;
            mots.push_back(nouveaumot);
        }
    }

    string nouveaumot = "";
    for (int j = derni�reEspace + 1; j < phrase.size(); ++j)
    {
        nouveaumot += phrase.at(j);
    }
    mots.push_back(nouveaumot);

    return mots;
}


/// <summary>
/// Retourne le mot le plus court de la liste. Dans le cas ou deux mots ont la m�me longueur, retourne le premier.
/// </summary>
/// <param name="mots"></param>
/// <returns></returns>
string TrouverMotPlusCourt(vector<string> mots)
{
    int longueurMot = INT_MAX;
    string mot = "";
    for (int i = 0; i < mots.size(); ++i)
    {
        if (mots.at(i).size() < longueurMot)
        {
            mot = mots.at(i);
            longueurMot = mot.size();
        }
    }
    return mot;
}

/// <summary>
/// Retourne le mot le plus long de la liste. Dans le cas ou deux mots ont la m�me longueur, retourne le premier.
/// </summary>
/// <param name="mots"></param>
/// <returns></returns>
string TrouverMotPlusLong(vector<string> mots) 
{
    int longueurMot = 0;
    string mot = "";
    for (int i = 0; i < mots.size(); ++i)
    {
        if(mots.at(i).size() > longueurMot)
        {
            mot = mots.at(i);
            longueurMot = mot.size();
        }
    }
    return mot;
}

/// <summary>
/// prend une liste de mots et retourne le nombre moyen de caract�re par mot
/// </summary>
/// <param name="mots"></param>
/// <returns></returns>
double TrouverLongueurMoy(vector<string> mots)
{
    int nbLettres = 0;
    for (int i = 0; i < mots.size(); ++i)
        nbLettres += mots.at(i).size();
    return nbLettres / (double)mots.size();
}

/// <summary>
/// Apelle tous les fonctions n�c�ssaires pour r�soudre l'ennonc� 1
/// </summary>
void EffectuerProbl�me1() 
{
    string phrase = DemanderPhrase();
    vector<string> mots = S�parerMots(phrase);
    cout << "le mot le plus court est : " << TrouverMotPlusCourt(mots) << "\n";
    cout << "le mot le plus long est : " << TrouverMotPlusLong(mots) << "\n";
    cout << "la longueur moyenne est : " << TrouverLongueurMoy(mots) << " lettres\n";
}

int main()
{
    EffectuerProbl�me1();
}

