#ifndef HOMEFILES_H
#define HOMEFILES_H

#include "krunner/abstractrunner.h"

#include <QHash>
#include <QIcon>


class HomeFilesRunner : public Plasma::AbstractRunner
{
    Q_OBJECT

public:
    HomeFilesRunner(QObject *parent, const QVariantList &args);

    void match(Plasma::RunnerContext &context);
    void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match);
    void createRunOptions(QWidget *widget);
    void reloadConfiguration();

protected Q_SLOTS:
    void init();
    void prepareForMatchSession();
    void matchSessionFinished();

private:
    QString m_path;
    QString m_triggerWord;
};

#endif
