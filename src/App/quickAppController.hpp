#pragma once

#include "quickQmlRegister.hpp"

#include <QObject>

namespace quick {

    class Notifications;

    namespace TypeInfo {
        class List;
    }

    namespace Code {
        class Editor;
        class Compiler;
    }

    namespace App {

        class Controller : public QObject {
            Q_OBJECT
            Q_PROPERTY(bool expanded READ isExpanded WRITE setExpanded NOTIFY expandedChanged);
            Q_PROPERTY(bool debugBuild READ isDebugBuild CONSTANT);
            Q_PROPERTY(QString version READ getVersion CONSTANT);
            Q_PROPERTY(quick::TypeInfo::List* typeList READ getTypeList CONSTANT);
            Q_PROPERTY(quick::Notifications* notifications READ getNotifications CONSTANT);
            Q_PROPERTY(quick::Code::Compiler* compiler READ getCompiler CONSTANT);
            Q_PROPERTY(quick::Code::Editor* editor READ getEditor CONSTANT);
        private:
            bool m_showList = false;
            bool m_expanded = false;
            QString m_version;
        private:
            Controller();
        public:
            static Qml::Register::Controller<Controller> Register;
            static Controller* instance;
            static auto Create() -> void;
            auto setExpanded(bool) -> void;
            auto isExpanded() -> bool;
            auto getVersion() -> QString;
            auto isDebugBuild() -> bool;
            auto getTypeList() -> TypeInfo::List*;
            auto getCompiler() -> Code::Compiler*;
            auto getEditor() -> Code::Editor*;
            auto getNotifications() -> Notifications*;
        signals:
            void expandedChanged();
        };
    }
}