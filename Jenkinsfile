pipeline {
  agent any
  stages {
    stage('test_job_1') {
      parallel {
        stage('test_job_1') {
          steps {
            build(job: 'test_job_1', propagate: true)
          }
        }

        stage('test_job_2') {
          steps {
            build(job: 'test_job_2', propagate: true)
          }
        }

      }
    }

    stage('Vote') {
      steps {
        sh 'echo "Finished"'
      }
    }

  }
}