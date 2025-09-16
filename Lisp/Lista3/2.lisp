(defun palindromep (L)
    (if (equal (reverse L) L)
        t
        nil
    )
)

(defun presentep (L a)
    (cond 
        ((null L) nil)
        ((atom L) (equal a L))
        ((equal a (car L)) t)
        ((presentep (car L) a) t)
        ((presentep (cdr L) a) t)
        (t nil)
    )
)

(defun misterio(s)
    (cond 
        ((null s) 1)
        ((atom s) 0)
        (t (max (+ 1 (misterio (car s))) (misterio (cdr s))))
    )
)

(defun estranho(p)
    (cond 
        ((null p) nil)
        ((atom p) p)
        (t (cons (estranho (car p)) (estranho (cdr p))))
    )
)
