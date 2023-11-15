(set-logic BV)

(define-fun bit-reset ((x (_ BitVec 32)) (bit (_ BitVec 32))) (_ BitVec 32)
    (let ((modulo-shift (bvand bit #x0000001f))) (ite (= modulo-shift #x00000000) (bvand #b11111111111111111111111111111110 x) (ite (= modulo-shift #x00000001) (bvand #b11111111111111111111111111111101 x) (ite (= modulo-shift #x00000002) (bvand #b11111111111111111111111111111011 x) (ite (= modulo-shift #x00000003) (bvand #b11111111111111111111111111110111 x) (ite (= modulo-shift #x00000004) (bvand #b11111111111111111111111111101111 x) (ite (= modulo-shift #x00000005) (bvand #b11111111111111111111111111011111 x) (ite (= modulo-shift #x00000006) (bvand #b11111111111111111111111110111111 x) (ite (= modulo-shift #x00000007) (bvand #b11111111111111111111111101111111 x) (ite (= modulo-shift #x00000008) (bvand #b11111111111111111111111011111111 x) (ite (= modulo-shift #x00000009) (bvand #b11111111111111111111110111111111 x) (ite (= modulo-shift #x0000000a) (bvand #b11111111111111111111101111111111 x) (ite (= modulo-shift #x0000000b) (bvand #b11111111111111111111011111111111 x) (ite (= modulo-shift #x0000000c) (bvand #b11111111111111111110111111111111 x) (ite (= modulo-shift #x0000000d) (bvand #b11111111111111111101111111111111 x) (ite (= modulo-shift #x0000000e) (bvand #b11111111111111111011111111111111 x) (ite (= modulo-shift #x0000000f) (bvand #b11111111111111110111111111111111 x) (ite (= modulo-shift #x00000010) (bvand #b11111111111111101111111111111111 x) (ite (= modulo-shift #x00000011) (bvand #b11111111111111011111111111111111 x) (ite (= modulo-shift #x00000012) (bvand #b11111111111110111111111111111111 x) (ite (= modulo-shift #x00000013) (bvand #b11111111111101111111111111111111 x) (ite (= modulo-shift #x00000014) (bvand #b11111111111011111111111111111111 x) (ite (= modulo-shift #x00000015) (bvand #b11111111110111111111111111111111 x) (ite (= modulo-shift #x00000016) (bvand #b11111111101111111111111111111111 x) (ite (= modulo-shift #x00000017) (bvand #b11111111011111111111111111111111 x) (ite (= modulo-shift #x00000018) (bvand #b11111110111111111111111111111111 x) (ite (= modulo-shift #x00000019) (bvand #b11111101111111111111111111111111 x) (ite (= modulo-shift #x0000001a) (bvand #b11111011111111111111111111111111 x) (ite (= modulo-shift #x0000001b) (bvand #b11110111111111111111111111111111 x) (ite (= modulo-shift #x0000001c) (bvand #b11101111111111111111111111111111 x) (ite (= modulo-shift #x0000001d) (bvand #b11011111111111111111111111111111 x) (ite (= modulo-shift #x0000001e) (bvand #b10111111111111111111111111111111 x) (bvand #b01111111111111111111111111111111 x))))))))))))))))))))))))))))))))))
(define-fun load-val ((base (_ BitVec 32)) (ptr (_ BitVec 32)) (mem (_ BitVec 32))) (_ BitVec 32)
    (ite (= ptr base) mem #x00000000))
(define-fun store ((base (_ BitVec 32)) (ptr (_ BitVec 32)) (mem (_ BitVec 32)) (val (_ BitVec 32))) (_ BitVec 32)
    (ite (= ptr base) val #x00000000))
(define-fun bit-reset-destam-base ((base (_ BitVec 32)) (mem (_ BitVec 32)) (bit (_ BitVec 32))) (_ BitVec 32)
    (let ((effective base)) (let ((lv (load-val base effective mem))) (let ((result (bit-reset lv bit))) (store base effective mem result)))))
(synth-fun btr-am ((base (_ BitVec 32)) (mem (_ BitVec 32)) (bit (_ BitVec 32))) (_ BitVec 32)
    ((Start (_ BitVec 32)) (Is (_ BitVec 32)))
    ((Start (_ BitVec 32) ((Variable (_ BitVec 32)) (store base Is Start Is)))
    (Is (_ BitVec 32) (  (Variable (_ BitVec 32)) (bvnot Is) (bvand Is Is) (bvshl Is Is) (load-val base Is Start)))))

(declare-var base (_ BitVec 32))
(declare-var mem (_ BitVec 32))
(declare-var bit (_ BitVec 32))
(constraint (= (btr-am base mem bit) (bit-reset-destam-base base mem bit)))

(check-synth)

