(defun fat (n)
    (if (= n 0)
        1
        (* n (fat(- n 1)))
    )
)

(defun choose (n k)
    (cond
        ((= k n) 1)
        ((= k 0) 1)
        (t (/ (fat n) (* (fat k) (fat (- n k)))))
    )
)