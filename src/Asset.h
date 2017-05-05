#ifndef ASSET_H
#define ASSET_H

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

class Asset 
{
public:
    Asset();
    Asset(const Asset& orig) = delete;
    
    /**
     * Wczytuje teksturę z pliku
     * 
     * @param key
     * @param filepath
     */
    void loadTexture(const std::string &key, const std::string &filepath);
    
    /**
     * Zwraca referencję do tekstury
     * 
     * @param key
     * @return 
     */
    sf::Texture& getTexture(const std::string &key);
    
    /**
     * Wczytuje czcionkę z pliku
     * 
     * @param key
     * @param filepath
     */
    void loadFont(const std::string &key, const std::string &filepath);
    
    /**
     * Zwraca referencję do czcionki
     * 
     * @param key
     * @return 
     */
    sf::Font& getFont(const std::string &key);
    
    virtual ~Asset();
private:
    
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;

};

#endif /* ASSET_H */

