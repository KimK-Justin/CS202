#include <iostream>
#include <string>
#include "NPC.h"
using namespace std;

NPC::NPC(){

}
NPC::NPC(string name, string desc, string dialogue){
    m_name = name;
    m_desc = desc;
    m_dialogue = dialogue;
}
void NPC::Talk(){
    cout << m_dialogue;
}
void NPC::Description(){
    cout << m_desc;
}
string NPC::GetName(){
    return m_name;
}
string NPC::GetDesc(){
    return m_desc;
}
string NPC::GetDialogue(){
    return m_dialogue;
}
