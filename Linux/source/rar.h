#ifndef RAR_H
#define RAR_H
#include <QString>
#include <QProcess>
#include <QApplication>
class RAR
{
public:
    RAR();
    int file(QString fileName){
        bool i=0;
        if(fileName.endsWith(".doc",Qt::CaseSensitive)||fileName.endsWith(".ppt",Qt::CaseSensitive)||fileName.endsWith(".pptx",Qt::CaseSensitive)||fileName.endsWith(".docx",Qt::CaseSensitive))
     {
            QString path=QApplication::applicationDirPath();
                QProcess proc;
                proc.start("/bin/bash");
                proc.waitForStarted();
                proc.execute("cd "+path);
                proc.execute("rar a -r "+fileName+".rar"+" "+fileName);
                proc.close();
                proc.waitForFinished();

            i=1;
        }
        return i;
    }

};

#endif // RAR_H
