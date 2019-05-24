#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>

class Canvas;

class Widget{
    private:
        int _x;
        int _y;
        std::weak_ptr<Canvas> _canvas;
    public:

        Widget(int x, int y, std::shared_ptr<Canvas> canvas):
            _x {x}, 
            _y {y},
            _canvas {canvas}{
            std::cout<<"Ctor Widget ("<<_x<<","<<_y<<")"<<std::endl;
            std::cout<<"canvas refs:"<<_canvas.use_count()<<std::endl;
        }

        Widget():Widget(0,0, nullptr){};

        ~Widget(){
            std::cout<<"Dtor Widget ("<<_x<<","<<_y<<")"<<std::endl;
        }

        void show(){
            std::cout<<"("<<_x<<","<<_y<<")"<<std::endl;
        }
        
};

class Canvas{
    private:
        std::shared_ptr<Widget> _widget;
    public:
        Canvas():_widget {nullptr}{
            std::cout<<"Ctor Canvas"<<std::endl;
        }
        ~Canvas(){
            std::cout<<"Dtor Canvas"<<std::endl;
        }

        void addWidget(std::shared_ptr<Widget> widget){
            _widget = widget;
            std::cout<<"use count:"<<_widget.use_count()<<std::endl;
        }
};

int main(){
    std::cout<<"begin"<<std::endl;
    {
        auto cnv = std::make_shared<Canvas>();
        auto wdg = std::make_shared<Widget>(10,20,cnv);
        cnv->addWidget(wdg);
    }    
    std::cout<<"end"<<std::endl;    
    return 0;
}
