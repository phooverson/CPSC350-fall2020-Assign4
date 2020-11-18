using namespace std;
template <class myType>
class ListNodeT {
public:
  myType data;
  ListNodeT *next;
  ListNodeT *prev;

  ListNodeT() {
    //do nothing
  }

  ListNodeT(myType d) {
    data = d;
    next = NULL;
  }

  ~ListNodeT() {

  }
};
