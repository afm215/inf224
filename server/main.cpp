//
// main.cpp
// Created on 21/10/2018
//
//string  _OS  = "none"
//
//#if defined(_WIN64) || defined(_WIN32)
//_OS = "none"
//#endif // _WIN64

#include <iostream>
#include "headers/multimedia.h"
#include "headers/video.h"
#include "headers/photo.h"
#include "headers/table.h"
#include <typeinfo>
#include "headers/film.h"
#include "headers/groupe.h"

#include "src/communication/tcpserver.h"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

//#include <sys/socket.h>




using namespace std;
using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {
public:
  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;
    std::istringstream iss(request);
    std::vector <std::string> split_request(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());


    if (split_request[0]=="addFilm"){
      // add Film : const std::string name, const std::string path_name, const int duree
      try{
        table.addFilm(split_request[1], split_request[2],  std::stoi(split_request[3]));
        response = "OK";
      }
      catch(exception e){
        response ="erreur dans les arguments entrés";
         }
      
      
    }

    if(split_request[0] == "addVideo"){
      //addVideo : const std::string name, const std::string path_name, const int duree
      try{
        table.addVideo(split_request[1], split_request[2], std::stoi(split_request[3]));
        response = "OK";
      }
      catch(exception e){
        response ="erreur dans les arguments entrés";
      }
    }

    if (split_request[0] == "addGroupe"){
      //addGroupe : string name
      try{
        table.addGroup(split_request[1]);
        response = "OK";
      }
      catch(exception e){
        response ="erreur dans les arguments entrés";
      }
    }

    if (split_request[0] == "addtoGroupe"){
      //addtogroupe: Multimedia name
      try{
        std::shared_ptr<Groupe> groupe = table.findGroupe(split_request[1], cout);
        if(groupe){
          response = "OK";
          std::shared_ptr<Multimedia> multi = table.findMultimedia(split_request[2], cout);
          if(!multi){
            response = "please create the multimedia first with add<Multimedia type>";
          }
          else{
            if(groupe){
              groupe->push_back(multi);
            }
            else{
              response = "group doesn't exist";
            }
            
          }
        }
        else{
          response = "groupe doesn't exist";
        }
      }
      catch (exception e){
        response ="erreur dans les arguments entrés";
      }
      
    }


    if (split_request[0] == "addPhoto"){
        //const string nom, const string path_file, const int latitude, const int longitude
        try{

          auto test = table.addPhoto(split_request[1], split_request[2], std::stoi(split_request[3]), std::stoi(split_request[4]));
          response="OK";
        }
        catch(exception e){
          response ="erreur dans les arguments entrés";
        }
    }

    if (split_request[0] == "play"){
      try{
        std::shared_ptr<Multimedia> multi = table.findMultimedia(split_request[1], cout);
        if(multi){
          multi->play();
          response = "OK";
        }     
        else{
          response = "No File found";
        }
      }
      catch(exception e){
        response ="erreur dans les arguments entrés";
      }

    }

    if(split_request[0] == "displayMultimedia"){
      try{
        stringstream flux;
        table.findMultimedia(split_request[1], flux);
        response = flux.str();
        int size = response.length();
        for (int i =0; i <size; i++){
          if (response [i] == '\n'){
            response[i] = '+';
          }
        }
      }
      catch (exception e){
        response ="erreur dans les arguments entrés";
      }
    }
     if(split_request[0] == "displayGroupe"){
       try{
        stringstream flux;
        table.findGroupe(split_request[1], flux);
        std::cout<<"in th  if"<<std::endl;
        response = flux.str();
        std::cout<<response<<std::endl;
        int size = response.length();
        for (int i =0; i <size; i++){
          if (response [i] == '\n'){
            response[i] = '+';
          }
        }
       }
      catch(exception e){
        response ="erreur dans les arguments entrés";
      }
    }
    cerr << "response: " << response << endl;
    
    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
  private:
    Table table = Table();
};

int main(int argc, char* argv[])
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());
  
  // cree l'objet qui gère les données
  shared_ptr<MyBase> base(new MyBase());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyBase::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}
