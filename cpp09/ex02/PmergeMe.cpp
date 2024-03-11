#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) {
    *this = obj;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & obj) {
    (void)obj;
    return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::invalidInput::what() const throw() {
	return "Invalid Input";
}

void PmergeMe::printVector(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int> deq) {
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;   
}

void PmergeMe::putArgToCtn(char **argv) {
    for (size_t i = 1; argv[i]; i++) {
        this->arg.push_back(argv[i]); // char *
    }

    int num;
    for (size_t i = 0; i < arg.size(); i++) {
        num = static_cast<int>(strtod(arg[i], NULL));
        if (num <= 0)
            throw invalidInput();
        this->argVec.push_back(num);
        this->argDeq.push_back(num);
    }
}

void PmergeMe::execute(char **argv) {
    std::cout.precision(16);
    putArgToCtn(argv);
    std::cout << "Before: ";
    printVector(argVec);

    clock_t start = clock();
    sortVector();
    clock_t fin = clock();
    vecTime = static_cast<double>(fin - start);

    std::cout << "After: ";
    printVector(mainVec);

    start = clock();
    sortDeque();
    fin = clock();
    deqTime = static_cast<double>(fin - start);

    std::cout << "Time to process a range of " << argVec.size()
     << " elements with std::vector : " << vecTime << "us\n";
    std::cout << "Time to process a range of " << argDeq.size()
     << " elements with std::deque : " << deqTime << "us\n";
}

// 0 1 1 3 5 11 21 ..
void PmergeMe::makeJacobArrVec() {
	jacobVec.push_back(0);
    jacobVec.push_back(1);

    size_t end = pairVec.size();
    if (pairVec.size() > 30)
        end = 30; // INT_MAX까지만 구하기
    for (size_t i = 0; i < end; i++) {
        jacobVec.push_back(jacobVec[i + 1] + 2 * jacobVec[i]);
    }
}

void PmergeMe::mergePairVec(int begin, int mid, int end) {
    std::vector<std::pair<int, int> > tmp = pairVec;
	int i = begin;
	int j = mid + 1;
	int k = begin;
    int l;

	while (i <= mid && j <= end) {
		if (pairVec[i].first <= pairVec[j].first)
			tmp[k++] = pairVec[i++];
		else
			tmp[k++] = pairVec[j++];
	}
	if (i > mid) {
		for (l = j; l <= end; l++)
			tmp[k++] = pairVec[l];
	}
	else {
		for (l = i; l <= mid; l++)
			tmp[k++] = pairVec[l];
	}
	for (l = begin; l <= end; l++)
		pairVec[l] = tmp[l];
}

void PmergeMe::sortPairVec(int begin, int end) {
    if (begin >= end)
        return ;
    
    int mid = (begin + end) / 2;
    sortPairVec(begin, mid);
    sortPairVec(mid + 1, end);
    mergePairVec(begin, mid, end);
}

void PmergeMe::bSearchVec(int end, int value) {
	int start = 0;
    int mid;

	while (start <= end) {
		mid = start + (end - start) / 2;
		if (value > this->mainVec[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	this->mainVec.insert(this->mainVec.begin() + start, value);
}

void PmergeMe::sortVector() {
    // 두개씩 묶은 pair로 저장하는데, 첫번째요소는 둘 중 큰 거, 두번째요소는 둘 중 작은 거
	for (size_t i = 0; i < argVec.size() - 1; i += 2) { // n / 2번 비교
        if (argVec[i] < argVec[i + 1])
		    this->pairVec.push_back(std::make_pair(argVec[i + 1], argVec[i]));
        else
            this->pairVec.push_back(std::make_pair(argVec[i], argVec[i + 1]));
	}
    // 인자 홀수인 경우 마지막 남은 하나 저장
    int odd = -1;
    if (argVec.size() % 2 == 1)
        odd = *(argVec.end() - 1);

    sortPairVec(0, pairVec.size() - 1); // recursive merge to sort first elements of Pairvec

    // 작은배열 맨 첫 값 큰 배열 맨 첫 값보다 항상 작음 => 큰 배열 맨 앞으로
    this->mainVec.push_back(this->pairVec[0].second);
    // 각 pair의 첫 요소는 mainVec에, 두번째 요소는 pendVec에 각각 저장. main은 정렬된 상태
	for (std::size_t i = 0; i < this->pairVec.size(); i++) {
		this->mainVec.push_back(this->pairVec[i].first);
        this->pendVec.push_back(this->pairVec[i].second);
    }

    makeJacobArrVec();

    size_t oldJacob = 1;
    size_t newJacob;
    for (size_t i = 2; i < jacobVec.size(); i++) {
        newJacob = jacobVec[i + 1]; // jacobVec index 30까지밖에 업슴;;..
        while (newJacob > oldJacob) {
            if (newJacob - 1 < pairVec.size()) {
                int endIdx = std::find(mainVec.begin(), mainVec.end(), pairVec[newJacob - 1].first) - mainVec.begin();
                bSearchVec(endIdx, pairVec[newJacob - 1].second);
            }
            newJacob--;
        }
        oldJacob = jacobVec[i + 1];
    }
	if (odd != -1) // 인자로 홀수개 받아서 하나 남을때
		bSearchVec(mainVec.size() - 1, odd);
}

void PmergeMe::makeJacobArrDeq() {
	jacobDeq.push_back(0);
    jacobDeq.push_back(1);

    size_t end = pairDeq.size();
    if (pairDeq.size() > 30)
        end = 30;
    for (size_t i = 0; i < end; i++) {
        jacobDeq.push_back(jacobDeq[i + 1] + 2 * jacobDeq[i]);
    }
}

void PmergeMe::mergePairDeq(int begin, int mid, int end) {
    std::deque<std::pair<int, int> > tmp = pairDeq;
	int i = begin;
	int j = mid + 1;
	int k = begin;
    int l;

	while (i <= mid && j <= end) {
		if (pairDeq[i].first <= pairDeq[j].first)
			tmp[k++] = pairDeq[i++];
		else
			tmp[k++] = pairDeq[j++];
	}
	if (i > mid) {
		for (l = j; l <= end; l++)
			tmp[k++] = pairDeq[l];
	}
	else {
		for (l = i; l <= mid; l++)
			tmp[k++] = pairDeq[l];
	}
	for (l = begin; l <= end; l++)
		pairDeq[l] = tmp[l];
}

void PmergeMe::sortPairDeq(int begin, int end) {
    if (begin >= end)
        return ;
    
    int mid = (begin + end) / 2;
    sortPairDeq(begin, mid);
    sortPairDeq(mid + 1, end);
    mergePairDeq(begin, mid, end);
}

void PmergeMe::bSearchDeq(int end, int value) {
	int start = 0;
    int mid;

	while (start <= end) {
		mid = start + (end - start) / 2;
		if (value > this->mainDeq[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	this->mainDeq.insert(this->mainDeq.begin() + start, value);
}


void PmergeMe::sortDeque() {
	for (size_t i = 0; i < argDeq.size() - 1; i += 2) {
        if (argDeq[i] < argDeq[i + 1])
		    this->pairDeq.push_back(std::make_pair(argDeq[i + 1], argDeq[i]));
        else
            this->pairDeq.push_back(std::make_pair(argDeq[i], argDeq[i + 1]));
	}
    int odd = -1;
    if (argDeq.size() % 2 == 1)
        odd = *(argDeq.end() - 1);

    sortPairDeq(0, pairDeq.size() - 1);

    this->mainDeq.push_back(this->pairDeq[0].second);
	for (std::size_t i = 0; i < this->pairDeq.size(); i++) {
		this->mainDeq.push_back(this->pairDeq[i].first);
        this->pendDeq.push_back(this->pairDeq[i].second);
    }

    makeJacobArrDeq();

    size_t oldJacob = 1;
    size_t newJacob;
    for (size_t i = 2; i < jacobDeq.size(); i++) {
        newJacob = jacobDeq[i + 1];
        while (newJacob > oldJacob) {
            if (newJacob - 1 < pairDeq.size()) {
                int endIdx = std::find(mainDeq.begin(), mainDeq.end(), pairDeq[newJacob - 1].first) - mainDeq.begin();
                bSearchDeq(endIdx, pairDeq[newJacob - 1].second);
            }
            newJacob--;
        }
        oldJacob = jacobDeq[i + 1];
    }
	if (odd != -1)
		bSearchDeq(mainDeq.size() - 1, odd);
}
