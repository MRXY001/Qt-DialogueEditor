#ifndef QSSHIGHLIGHTEDITOR_H
#define QSSHIGHLIGHTEDITOR_H

#include <QObject>
#include <QPlainTextEdit>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class QSSHighlightEditor : public QPlainTextEdit
{
public:
    QSSHighlightEditor(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *e) override;
};


class QSSHighlighter : public QSyntaxHighlighter
{
    struct QSSRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

public:
    QSSHighlighter(QTextDocument* parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;
};

#endif // QSSHIGHLIGHTEDITOR_H
