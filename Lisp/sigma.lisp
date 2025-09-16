(defun sigma (m n)
 (if (= m n)
    n
    (+ m (sigma (+ m 1) n))
 )
)