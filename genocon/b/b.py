from Bio import pairwise2
# from Bio.pairwise2 import format_alignment

def main():

    s1 = input()
    s2 = input()

    tmp_align_lst = []

    for a in pairwise2.align.globalms(s1, s2, 1, -3, -5, -5):
        # print(format_alignment(*a))
        tmp_align_lst.append([a.seqA,a.seqB, a.score])

    # print(tmp_align_lst)

    a_top = sorted(tmp_align_lst,key=lambda x: x[-1],reverse=True)[0]
    print(a_top[0])
    print(a_top[1])


if __name__ == '__main__':
    main()