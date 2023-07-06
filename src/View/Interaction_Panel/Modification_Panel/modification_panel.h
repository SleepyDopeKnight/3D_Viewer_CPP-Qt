#ifndef MODIFICATION_PANEL_H
#define MODIFICATION_PANEL_H

#include <QWidget>

namespace Ui {
class ModificationPanel;
}

class ModificationPanel : public QWidget {
  Q_OBJECT

 public:
  explicit ModificationPanel(QWidget *parent = nullptr);
  ~ModificationPanel();

  void SetEnabledModifiers(bool status);

 private:
  Ui::ModificationPanel *ui;
};

#endif  // MODIFICATION_PANEL_H
