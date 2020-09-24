#include "dialogueeditor.h"

DialogueEditor::DialogueEditor(QWidget *parent) : QWidget(parent)
{
    initView();
    initStyle();
}

void DialogueEditor::initView()
{
    name_label = new QLabel("名字", this);
    name_edit = new QLineEdit(this);
    said_label = new QLabel("说的话", this);
    said_edit = new QPlainTextEdit(this);
    narr_label = new QLabel("旁白", this);
    narr_edit = new QPlainTextEdit(this);
    style_label = new QLabel("样式表", this);
    style_edit = new QPlainTextEdit(this);
    name_check = new QCheckBox("显示名字", this);
    delete_bucket_button = new QPushButton("删除此行", this);
    export_picture_button = new QPushButton("导出图片", this);
    export_text_button = new QPushButton("导出文字", this);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addWidget(name_label);
    vlayout->addWidget(name_edit);
    vlayout->addWidget(said_label);
    vlayout->addWidget(said_edit);
    vlayout->addWidget(narr_label);
    vlayout->addWidget(narr_edit);
    vlayout->addWidget(style_label);
    vlayout->addWidget(style_edit);
    vlayout->addWidget(name_check);
    QHBoxLayout *button_hlayout = new QHBoxLayout;
    button_hlayout->addWidget(delete_bucket_button);
    button_hlayout->addWidget(export_picture_button);
    button_hlayout->addWidget(export_text_button);
    vlayout->addLayout(button_hlayout);

    vlayout->setMargin(0);
}

void DialogueEditor::initStyle()
{
}

void DialogueEditor::setBucket(DialogueBucket *bucket)
{
    current_bucket = bucket;
    if (bucket == nullptr)
    {
        name_label->setEnabled(false);
        name_edit->setEnabled(false);
        said_label->setEnabled(false);
        said_edit->setEnabled(false);
        narr_label->setEnabled(false);
        narr_edit->setEnabled(false);
        style_label->setEnabled(false);
        style_edit->setEnabled(false);
        name_check->setEnabled(false);
        delete_bucket_button->setEnabled(false);
    }

    if (bucket->isNarrator())
    {
        name_label->setEnabled(false);
        name_edit->setEnabled(false);
        said_label->setEnabled(false);
        said_edit->setEnabled(false);
        narr_label->setEnabled(true);
        narr_edit->setEnabled(true);
        style_label->setEnabled(false);
        style_edit->setEnabled(false);
        name_check->setEnabled(false);
        delete_bucket_button->setEnabled(false);
    }
    else
    {
        name_label->setEnabled(true);
        name_edit->setEnabled(true);
        said_label->setEnabled(true);
        said_edit->setEnabled(true);
        narr_label->setEnabled(false);
        narr_edit->setEnabled(false);
        style_label->setEnabled(true);
        style_edit->setEnabled(true);
        name_check->setEnabled(true);
        delete_bucket_button->setEnabled(true);
    }
}