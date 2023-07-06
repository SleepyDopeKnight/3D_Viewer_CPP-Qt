#include "style_panel.h"

#include "ui_style_panel.h"

#include "iostream"

StylePanel::StylePanel(QWidget *parent)
    : QWidget(parent), ui(new Ui::StylePanel) {
  ui->setupUi(this);

  connect(ui->spinBox_color_back_r, SIGNAL(valueChanged(int)), this,
          SLOT(UpdateColorBackR()));
}

StylePanel::~StylePanel() { delete ui; }

void StylePanel::SetEnabledModifiers(bool status) {
  ui->line_type_dotted->setEnabled(status);
  ui->line_type_solid->setEnabled(status);

  ui->display_method_none->setEnabled(status);
  ui->display_method_circle->setEnabled(status);
  ui->display_method_square->setEnabled(status);

  ui->projection_f->setEnabled(status);
  ui->projection_p->setEnabled(status);

  ui->spinBox_color_line_r->setEnabled(status);
  ui->spinBox_color_line_g->setEnabled(status);
  ui->spinBox_color_line_b->setEnabled(status);

  ui->spinBox_color_point_r->setEnabled(status);
  ui->spinBox_color_point_g->setEnabled(status);
  ui->spinBox_color_point_b->setEnabled(status);

  ui->spinBox_color_back_r->setEnabled(status);
  ui->spinBox_color_back_g->setEnabled(status);
  ui->spinBox_color_back_b->setEnabled(status);
}

void StylePanel::ConnectPanelElements() {}

void StylePanel::UpdateColorBackR() { std::cout << "hui" << std::endl; }
