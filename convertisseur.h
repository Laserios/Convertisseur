#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

#include <QWidget>


class Convertisseur : public QWidget
{
    Q_OBJECT

public:
    explicit Convertisseur(QWidget *parent = 0);

    double CelciustoFarenheit(double c);
    double FarenheittoCelcius(double f);
    double MetretoYard(double m);
    double YardtoMetre(double y);
    double KilometretoNautique(double km);
    double NautiquetoKilometre(double MN);
    double KilometreheuretoNoeud(double kmh);
    double NoeudtoKilometreheure(double kn);

};


#endif // CONVERTISSEUR_H
