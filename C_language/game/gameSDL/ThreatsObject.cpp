#include "ThreatsObject.h"

// contructor
ThreatsObject::ThreatsObject() {
  rect_.x = SCREEN_WIDTH;
  rect_.y = SCREEN_HEIGHT*0.5;
  rect_.w = WIDTH_THREAT;
  rect_.h = HEIGHT_THREAT;
  x_val_ = 0;
  y_val_ = 0;
}
//destructor
ThreatsObject::~ThreatsObject() {}

void ThreatsObject::InitBullet(BulletObject* p_bullet) {
  if (p_bullet != NULL) {
    bool ret = p_bullet->LoadIMG("sphere.png");
    if (ret) {
      p_bullet->set_is_move(true);
      p_bullet->SetW_H(WIDTH_SPHERE, HEIGHT_SPHERE);
      p_bullet->set_type(BulletObject::SPHERE);
      p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.5); // xac dinh vi tri cua vien dan
      p_bullet_list_.push_back(p_bullet); // them vao p_bullet_list_
    }
  }
}
void ThreatsObject::MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit) {
  for (int i = 0; i < p_bullet_list_.size(); i++) {
    BulletObject* p_bullet = p_bullet_list_.at(i);
    if (p_bullet != NULL) {
      if (p_bullet->get_is_move()) {
        p_bullet->Show(des);
        p_bullet->HandleMoveRightToLeft();
      }else {// duoc lap lai khi cham bien trai
        p_bullet->set_is_move(true);
        p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.5);
      }
    }
  }
}

void ThreatsObject::HandleMove(const int& border_x, const int& border_y) {
  rect_.x -= x_val_;
  if (rect_.x < 0) {
    rect_.x = SCREEN_WIDTH;
    rect_.y = SDL_CommonFunction::Random(0, SCREEN_HEIGHT*0.75); 
  }
}

void ThreatsObject::HandleInputAction(SDL_Event events) {}