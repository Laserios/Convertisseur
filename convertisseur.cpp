#include "convertisseur.h"
#include "ihmconvertisseur.h"


Convertisseur::Convertisseur(QWidget *parent) : QWidget(parent)
{

}



double Convertisseur::CelciustoFarenheit(double c)
{
    return c * 1.8 + 32;
}

double Convertisseur::FarenheittoCelcius(double f)
{
    return (f - 32) * 5/9;
}

double Convertisseur::MetretoYard(double m)
{
    return m * 1.09361;
}

double Convertisseur::YardtoMetre(double yd)
{
    return yd / 1.09361;
}

double Convertisseur::KilometretoNautique(double km)
{
    return km * 0.539957;
}

double Convertisseur::NautiquetoKilometre(double MN)
{
    return MN / 0.539957;
}

double Convertisseur::KilometreheuretoNoeud(double kmh)
{
    return kmh * 0.539957;
}

double Convertisseur::NoeudtoKilometreheure(double kn)
{
    return kn / 0.539957;
}
