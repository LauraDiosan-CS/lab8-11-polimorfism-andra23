#pragma once
class MyException {
protected:
	const char* message;
public:
	MyException(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};

/*class MyExceptionDerived : public MyException {
private:
	const char* messageDerived;
public:
	MyExceptionDerived(const char* m) : MyException(m), messageDerived(m) {
	}
	const char* getMessage() {
		return messageDerived;
	}
};
*/
