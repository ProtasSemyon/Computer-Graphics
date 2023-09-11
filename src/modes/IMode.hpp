

class IMode {
public:
  IMode() = default;

  virtual ~IMode() = default;

  virtual void draw() = 0;

  virtual void update() = 0;
};