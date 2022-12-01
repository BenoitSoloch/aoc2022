#include <QCoreApplication>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("inputs.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error trying to open the file";
        return 0;
    }

    QTextStream in(&file);
    QString content = in.readAll();

    QStringList elfs = content.split("\n\n");
    QVector<int> elfsTotalCal;

    for(QString part: elfs){
        QStringList elfsCal = part.split("\n");
        int sum = 0;
        for(QString sPart: elfsCal)
            sum += sPart.toInt();

        elfsTotalCal.append(sum);
    }

    std::sort(elfsTotalCal.begin(), elfsTotalCal.end(), std::greater<int>());

    qDebug() << "PART1: " << elfsTotalCal[0];
    qDebug() << "PART2: " << elfsTotalCal[0] + elfsTotalCal[1] + elfsTotalCal[2];

    return a.exec();
}
