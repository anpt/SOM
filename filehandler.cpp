#include "filehandler.hpp"
filehandler::filehandler(QObject *parent) : QObject(parent)
{

}

void filehandler::newTodo(QString text, QString fileName, QString date)
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    path.append(fileName);
    QFile outfile;
    outfile.setFileName(path);
    outfile.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
    qDebug() << path;
    QTextStream stream(&outfile);
    stream <<"* TODO " << text << "\n" << "<" + date << ">\n";
    outfile.close();
}
void filehandler::clockin(QString header, QString fileName)
{
    std::vector<QString> lines;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    path.append(fileName);
    QFile outfile;
    outfile.setFileName(path);
    outfile.open(QIODevice::ReadOnly);
    QTextStream instream(&outfile);
    std::vector<QString>::iterator it;
    qDebug() << "Ska börja klocka in";
//skriv in alla strängar i en vektor
    do{
        lines.push_back(instream.readLine());
    }while(!instream.atEnd());
    it = lines.begin();
    for (int i = 0; i < lines.size(); ++i)
    {
        it++;
        if (lines.at(i).contains(header))
        {
            //insert line.
            lines.insert(it, ("CLOCK: " + cTime()));
			
        }
    }
    outfile.close();
    //skriv till file
     qDebug() << "har klockat in";
    outfile.setFileName(path);
    outfile.open(QIODevice::WriteOnly);
    QTextStream outstream(&outfile);
    qDebug() << lines.size();
    for (int i = 0; i < lines.size(); ++i)
    {
        outstream << lines.at(i);
        endl(outstream);
    }
    outfile.close();
    qDebug() << "Är färdig med klockningen";
}
void filehandler::clockout(QString header, QString fileName )
{
    std::vector<QString> lines;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    path.append(fileName);
    QFile outfile;
    outfile.setFileName(path);
    outfile.open(QIODevice::ReadOnly);
    QTextStream instream(&outfile);
    std::vector<QString>::iterator it;
    qDebug() << "Ska klocka ut";
	
//skriv in alla strängar i en vektor
    do{
        qDebug()<<"Tick";
        lines.push_back(instream.readLine());
    }while(!instream.atEnd());
    it = lines.begin();
    qDebug() << "Ska klocka ut2";
    qDebug() << lines.size();
    for (int i = 0; i < lines.size(); ++i)
    {
        if (lines.at(i).contains(header))
        {
            qDebug() << "Är i if satsen";
            //fix lines
            qDebug() << i;
            lines[i+1] = lines[i+1] + QString::fromLatin1("--");
            qDebug() << "Kommit ett steg";
            lines[i+1] = lines[i+1]+ cTime();
        }
    }
    qDebug() << "har klockat ut";
    outfile.close();
    //skriv till file

    outfile.setFileName(path);
    outfile.open(QIODevice::WriteOnly);
    QTextStream outstream(&outfile);
    for (int i = 0; i < lines.size(); ++i)
    {
        outstream << lines.at(i);
        endl(outstream);
    }
    qDebug("HAr klockat ut");
    outfile.close();
}

QString filehandler::cTime()
{
	std::string retVal;
	std::time_t t = std::time(0);
	struct tm * now = localtime(&t);
	int year, month, day;
	year = 1900 + now->tm_year;
	month = 1 + now->tm_mon;
	day = now->tm_mday;
	retVal =  "[";
	retVal += std::to_string(year);
	retVal += "-";
	retVal += std::to_string(month);
	retVal += "-";
	if (day<10)
	{
		retVal += "0";
	}
	retVal += std::to_string(day);
	
	if (now->tm_wday == 1)
	{
		retVal += " Mon ";
	}else if (now->tm_wday == 2)
	{
		retVal += " Tus ";
	} else if (now->tm_wday == 3)
	{
		retVal += " Wed ";
	} else if (now->tm_wday == 4)
	{
		retVal += " Thu ";
	} else if (now->tm_wday == 5)
	{
		retVal += " Fri ";
	} else if (now->tm_wday == 6)
	{
		retVal += " Sat ";
	} else if (now->tm_wday == 0)
	{
		retVal += " Sun ";
	}
	if (now->tm_hour<10)
	{
		retVal += "0";
	}
	retVal += std::to_string(now->tm_hour);
	retVal += ":";
	if (now->tm_min < 10)
	{
		retVal += "0";
	}
	
	retVal += std::to_string(now->tm_min);
	retVal += "]";
    return QString::fromLatin1(retVal.c_str());
}

void filehandler::listHeaders(QString fileName)
{
    std::vector<QString> lines;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    path.append(fileName);
    QFile outfile;
    outfile.setFileName(path);
    qDebug() << path;
    headerList.clear();
    if(outfile.open(QIODevice::ReadOnly)){
        QTextStream instream(&outfile);
        qDebug() << "Kan öppna fil";
        QStringList tmp;
        do{
            lines.push_back(instream.readLine());
        }while(!instream.atEnd());
        for (int i = 0; i < lines.size(); ++i)
        {
            if (lines.at(i).contains("*"))
            {
                headerList.append(new todoHeader(lines.at(i)));
            }
        }
        outfile.close();
    }
}

QList<QObject*> filehandler::list()
{
    return headerList;
}
