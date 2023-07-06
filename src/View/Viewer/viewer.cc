#include "viewer.h"

#include "ui_viewer.h"

Viewer::Viewer(s21::ObjectHandlerController *object_controller,
               s21::StyleHandlerController *style_controller, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Viewer),
      object_controller_(object_controller),
      style_controller_(style_controller) {
  ui->setupUi(this);

  object_observer_ = new ObjectObserver(object_controller, style_controller);
  modification_panel_ = new ModificationPanel();
  style_panel_ = new StylePanel();

  ui->object_observer_window->addWidget(object_observer_);
  ui->modification_panel->addWidget(modification_panel_);
  ui->style_panel->addWidget(style_panel_);


  connect(ui->button_open_file, SIGNAL(clicked()), this, SLOT(OpenFile()));
}

Viewer::~Viewer() { delete ui; }

void Viewer::OpenFile() {
  QString file_path = (QFileDialog::getOpenFileName(
      this, "Open a file", "./obj_templates/", "(*.obj)"));
  if (object_controller_->RecordDataFromFile(file_path.toStdString())) {
    ui->input_filename->setText("  " + file_path);
    ui->info_of_object->setText(
        "vertexes: " +
        QString::number(object_controller_->GetData().vertices.size()) + "\t" +
        "facets: " +
        QString::number(object_controller_->GetData().facets.size()));
    object_observer_->GetData();
    style_panel_->SetEnabledModifiers(true);
    modification_panel_->SetEnabledModifiers(true);
  }
}
