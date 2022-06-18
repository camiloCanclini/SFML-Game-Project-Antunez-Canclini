#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Background : public Drawable
{
public:
    Background(string textureSourcePath, sf::RenderWindow &window){
        textureBackground.loadFromFile(textureSourcePath);
        background.setTexture(textureBackground);
        background.setScale((float)window.getSize().x/(float)textureBackground.getSize().x,(float)window.getSize().y/(float)textureBackground.getSize().y);
        window.draw(background);
    }
    void draw(RenderTarget &target, RenderStates states) const override
    {
        target.draw(background,states);
    }
private:
    Texture textureBackground;
    Sprite background;

   
};

