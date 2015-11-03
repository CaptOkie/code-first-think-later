#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../db/storage.h"
#include "../db/user.h"

namespace Ui {
    class MainWindow;
}

/**
 * @brief The MainWindow class
 *
 * The main window for the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        /**
         * @brief MainWindow Creates a new instance.
         * @param db The storage object.
         * @param parent The parent widget.
         */
        explicit MainWindow(Storage& db, QWidget* parent = 0);
        ~MainWindow();

    private slots:
        /**
         * @brief showLogin Shows the login.
         */
        void showLogin();

        /**
         * @brief showHome Shows the appropriate home screen for the user.
         */
        void showHome(User*);

    private:
        Ui::MainWindow* ui; // The UI
        Storage& db;        // The storage object

        /**
         * @brief changeView Changes the view of the main window.
         * @param widget The widget to change the view to.
         */
        void changeView(QWidget* widget);
};

#endif // MAINWINDOW_H
