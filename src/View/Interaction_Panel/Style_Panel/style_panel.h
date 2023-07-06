#ifndef STYLE_PANEL_H
#define STYLE_PANEL_H

#include <QWidget>
#include <QtWidgets/QSpinBox>
#include <map>

namespace Ui {
class StylePanel;
}

class StylePanel : public QWidget {
  Q_OBJECT

 public:
  ~StylePanel();

  explicit StylePanel(QWidget *parent = nullptr);

  void SetEnabledModifiers(bool status);

 private:
  Ui::StylePanel *ui;

  void ConnectPanelElements();

 private slots:
//  std::map<std::string, float> colors
  void UpdateColorBackR();
};

#endif  // STYLE_PANEL_H
