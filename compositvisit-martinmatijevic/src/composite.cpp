#include "composite.h"
#include <cctype>
#include <stdexcept>

using namespace std;

void Title::addComponent(Component * cp){
   if((typeid(*cp)!= typeid(Chapter)) && (typeid(*cp) != typeid(Paragraph))) throw runtime_error("komponenta nije odgovarajuceg tipa!(paragraf niti chapter)");
   mChildren.push_back(cp);
}

void Chapter::addComponent(Component * cp){
   if(typeid(*cp) != typeid(Paragraph)) throw runtime_error("komponenta nije odgovarajuceg tipa(paragraf)!");
   mChildren.push_back(cp);
}

void Component::read(ifstream & infile){
    string s;
    vector<string> tekst;
    while(std::getline(infile, s)){
        tekst.push_back(s);
    }
    Chapter * chapter = new Chapter;
    Paragraph * paragraf = new Paragraph;
    Title * naslov = new Title;
    for(unsigned int i=0; i < tekst.size(); i++){
        if(tekst[i][0] == '=' && tekst[i][1] == ' '){
            naslov->tekst =tekst[i].substr(2);
            mParent = naslov;
        }
        if(tekst[i][0] == '=' && tekst[i][1] == '=' && tekst[i][2] == ' '){
            chapter->tekst = tekst[i].substr(3);
            naslov->addComponent(chapter);
            chapter->addComponent(paragraf);
        }
        if(tekst[i].empty()) {return 0;}
    }
}

void HTMLVisitor::visitComponent(Component * c){
    visitTitle(c->mParent);
    for(auto it = c->mParent->mChildren.begin(); it != c->mParent->mChildren.end(); ++it){
        if(typeid(*it) == typeid(Chapter)){
            for(auto itt = (*it)->mChildren.begin(); itt != (*it)->mChildren.end(); ++itt)
                visitParagraph(*itt);
        }
        else if( typeid(*it) == typeid(Paragraph)) visitParagraph(*it);
    }
}

void HTMLVisitor::visitTitle(Component * t){
    (t->mTitle).insert(0, "<h1>");
    (t->mTitle).append(t->tekst);
    (t->mTitle).append("</h1>");
}

void HTMLVisitor::visitChapter(Component * c){
    (c->mChapter).insert(0, "<h2>");
    (c->mChapter).append(c->tekst);
    (c->mChapter).append("</h2>");
}

void HTMLVisitor::visitParagraph(Component * p){
    bool prvaZvijezda=false;
    bool prvaCrta=false;
    string temp="";
    for(unsigned int i = 0; i!= p->tekst.size(); i++){
        if(p->tekst[i] == '*' && !prvaZvijezda){
            temp += "<b>";
            prvaZvijezda = true;
        }
        else if(p->tekst[i] == '*' && prvaZvijezda){
            temp += "</b>";
            prvaZvijezda = false;
        }
        else if(p->tekst[i] == '_' && !prvaCrta){
            temp += "<i>";
            prvaCrta = true;
        }
        else if(p->tekst[i] == '_' && prvaCrta){
            temp += "</i>";
            prvaCrta = false;
        }
        else temp += p->tekst[i];
    }
    (p->mText).append(temp);
}
