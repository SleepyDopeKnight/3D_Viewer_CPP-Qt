#include "modification_panel.h"

#include "ui_modification_panel.h"

ModificationPanel::ModificationPanel(QWidget *parent)
    : QWidget(parent), ui(new Ui::ModificationPanel) {
  ui->setupUi(this);
}

ModificationPanel::~ModificationPanel() { delete ui; }

void ModificationPanel::SetEnabledModifiers(bool status) {
  ui->spinBox_scale->setEnabled(status);

  ui->spinBox_x_angle->setEnabled(status);
  ui->spinBox_y_angle->setEnabled(status);
  ui->spinBox_z_angle->setEnabled(status);

  ui->spinBox_x->setEnabled(status);
  ui->spinBox_y->setEnabled(status);
  ui->spinBox_z->setEnabled(status);
}
