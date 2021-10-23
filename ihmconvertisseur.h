#ifndef IHMCONVERTISSEUR_H
#define IHMCONVERTISSEUR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QAction>
#include <QVBoxLayout>
#include "convertisseur.h"

class Convertisseur;

class IHMConvertisseur : public QWidget
{
    Q_OBJECT

private:
    QPushButton *btnQuitter;
    QPushButton *btnConvertir;
    QLabel *Unite;
    QLabel *Resultat;
    QComboBox *comboChoix;
    QLineEdit *Saisie;
    Convertisseur *convert;
    int last_current_index;
    QDoubleValidator *valid;

public:
    IHMConvertisseur(QWidget *parent = 0);
    ~IHMConvertisseur();

private slots:
    void convertir();
    void permuter(int i);

signals:

};
#endif // IHMCONVERTISSEUR_H
